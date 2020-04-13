#pragma once
#include "pch.h"
#include "IO.h"

namespace PLX
{
    class BinaryReader
    {
    private:
        std::ifstream Stream;
        std::streampos Length;
    public:
        // Opens a new stream and disposes of the previous one (if open)
        void Open(std::string filePath)
        {
            Stream.close();
            Stream = std::ifstream(filePath, std::ios::binary);

            if (!Stream)
            {
                Stream.close();
                throw std::exception("PLX::BinaryReader: Failed to create Stream for BinaryReader");
            }
            else
            {
                Stream.exceptions(std::ifstream::failbit | std::ifstream::badbit);
                Stream.seekg(0, std::ios::end);
                Length = Stream.tellg();
                Stream.seekg(0, std::ios::beg);
            }
        }
        // Inits a new Binary Reader
        BinaryReader() {}
        // Inits a new Binary Reader and opens the file
        BinaryReader(std::string filePath)
        {
            Open(filePath);
        }
        // Reads a signed 8bit int from the stream
        int8_t ReadInt8() { return ReadStruct<int8_t>(); }
        // Reads an unsigned 8bit int from the stream
        uint8_t ReadUInt8() { return ReadStruct<uint8_t>(); }
        // Reads a signed 16bit int from the stream
        int16_t ReadInt16() { return ReadStruct<int16_t>(); }
        // Reads an unsigned 16bit int from the stream
        uint16_t ReadUInt16() { return ReadStruct<uint16_t>(); }
        // Reads a signed 32bit int from the stream
        int32_t ReadInt32() { return ReadStruct<int32_t>(); }
        // Reads an unsigned 32bit int from the stream
        uint32_t ReadUInt32() { return ReadStruct<uint32_t>(); }
        // Reads a signed 64bit int from the stream
        int64_t ReadInt64() { return ReadStruct<int64_t>(); }
        // Reads an unsigned 64bit int from the stream
        uint64_t ReadUInt64() { return ReadStruct<uint64_t>(); }
        // Reads a single precision float from the stream
        float ReadFloat() { return ReadStruct<float>(); }
        // Reads a double precision float from the stream
        double ReadDouble() { return ReadStruct<double>(); }
        // Reads a struct/type from the stream of the given type
        template <class T>
        T ReadStruct()
        {
            T result;
            ReadBytes((char*)&result, sizeof(result));
            return result;
        }
        // Reads a struct/type from the stream of the given type
        template <class T>
        T ReadStruct(std::streamoff offset)
        {
            auto currentPos = GetPosition();
            Seek(offset, SeekOrigin::Begin);

            T result;
            ReadBytes((char*)&result, sizeof(result));

            Seek(currentPos, SeekOrigin::Begin);

            return result;
        }
        // Reads an array of the given struct/type from the stream of the given type
        template <class T>
        std::vector<T> ReadArray(size_t size)
        {
            std::vector<T> results(size);
            ReadBytes((char*)&results.front(), sizeof(T) * size);
            return results;
        }
        // Reads an array of the given struct/type from the stream of the given type
        template <class T>
        std::vector<T> ReadArray(size_t size, std::streamoff offset)
        {
            auto currentPos = GetPosition();
            Seek(offset, SeekOrigin::Begin);

            std::vector<T> results(size);
            ReadBytes((char*)&results.front(), sizeof(T) * size);

            Seek(currentPos, SeekOrigin::Begin);

            return results;
        }
        // Reads a string terminated by a null byte
        std::string ReadNullTerminatedString()
        {
            std::stringstream result;
            auto character = ReadInt8();

            while (character != 0)
            {
                result << character;
                character = ReadInt8();
            }

            return result.str();
        }
        // Reads a string terminated by a null byte
        std::string ReadNullTerminatedString(std::streamoff offset)
        {
            auto currentPos = GetPosition();
            Seek(offset, SeekOrigin::Begin);

            std::stringstream result;
            auto character = ReadInt8();

            while (character != 0)
            {
                result << character;
                character = ReadInt8();
            }

            Seek(currentPos, SeekOrigin::Begin);

            return result.str();
        }
        // Reads a string terminated by a null byte
        std::unique_ptr<char[]> ReadNullTerminatedStringRaw()
        {
            std::stringstream result;
            auto character = ReadInt8();

            while (character != 0)
            {
                result << character;
                character = ReadInt8();
            }

            auto str = result.str();
            auto ptr = std::make_unique<char[]>(str.length() + 1);
            std::memcpy(ptr.get(), str.c_str(), str.length() + 1);

            return ptr;
        }
        // Reads a string terminated by a null byte
        std::string ReadUtf16NullTerminatedString()
        {
            std::stringstream result;
            auto character = ReadStruct<wchar_t>();

            while (character != 0)
            {
                result << character;
                character = ReadStruct<wchar_t>();
            }

            return result.str();
        }
        // Reads a string terminated by a null byte
        std::string ReadUtf16NullTerminatedString(std::streamoff offset)
        {
            auto currentPos = GetPosition();
            Seek(offset, SeekOrigin::Begin);

            std::stringstream result;
            auto character = (uint8_t)ReadStruct<wchar_t>();

            while (character != 0)
            {
                result << character;
                character = (uint8_t)ReadStruct<wchar_t>();
            }

            Seek(currentPos, SeekOrigin::Begin);

            return result.str();
        }
        // Reads bytes from the stream
        std::unique_ptr<char[]> ReadBytes(size_t count, size_t& bytesRead)
        {
            auto result = std::make_unique<char[]>(count);
            bytesRead = ReadBytes(result.get(), count);
            return result;
        }
        // Reads bytes from the stream
        std::unique_ptr<char[]> ReadBytes(size_t count, size_t& bytesRead, std::streamoff offset)
        {
            auto currentPos = GetPosition();
            Seek(offset, SeekOrigin::Begin);

            auto result = std::make_unique<char[]>(count);
            bytesRead = ReadBytes(result.get(), count);

            Seek(currentPos, SeekOrigin::Begin);

            return result;
        }
        // Reads bytes from the stream
        virtual size_t ReadBytes(char* data, size_t count)
        {
            size_t result = 0;

            if (Stream)
            {
                Stream.read(data, count);
                result = (size_t)Stream.gcount();
            }

            return result;
        }
        // Reads bytes from the stream
        size_t ReadBytes(char* data, size_t count, std::streamoff offset)
        {
            auto currentPos = GetPosition();
            Seek(offset, SeekOrigin::Begin);

            auto result = ReadBytes(data, count);

            Seek(currentPos, SeekOrigin::Begin);

            return result;
        }
        // Seeks to the position in the stream
        virtual void Seek(std::streamoff offset, SeekOrigin origin)
        {
            Stream.seekg(offset,
                origin == SeekOrigin::Begin ? std::ios::beg :
                origin == SeekOrigin::End ? std::ios::end : std::ios::cur);
        }
        // Seeks to the position in the stream from the start
        virtual void Seek(std::streamoff offset)
        {
            Seek(offset, SeekOrigin::Begin);
        }
        // Gets the current stream position
        virtual std::streamoff GetPosition()
        {
            return Stream.tellg();
        }
        // Gets the current stream position
        virtual std::streampos GetLength()
        {
            return Length;
        }
    };
}