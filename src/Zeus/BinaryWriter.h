#pragma once
#include "pch.h"
#include "IO.h"

namespace PLX
{
    class BinaryWriter
    {
    private:
        std::ofstream Stream;
    public:
        // Opens a new stream and disposes of the previous one (if open)
        void Open(std::string filePath)
        {
            Stream.close();
            Stream = std::ofstream(filePath, std::ios::binary);

            if (!Stream)
            {
                Stream.close();
                throw std::exception("PLX::BinaryReader: Failed to create Stream for BinaryWriter");
            }
        }
        // Inits a new Binary Writer
        BinaryWriter() {}
        // Inits a new Binary Writer and opens the file
        BinaryWriter(std::string filePath)
        {
            Open(filePath);
        }
        // Writes a signed 8bit int to the stream
        void WriteInt8(int8_t val) { Write<int8_t>(val); }
        // Writes an unsigned 8bit int to the stream
        void WriteUInt8(uint8_t val) { Write<uint8_t>(val); }
        // Writes a signed 16bit int to the stream
        void WriteInt16(int16_t val) { Write<int16_t>(val); }
        // Writes an unsigned 16bit int to the stream
        void WriteUInt16(uint16_t val) { Write<uint16_t>(val); }
        // Writes a signed 32bit int to the stream
        void WriteInt32(int32_t val) { Write<int32_t>(val); }
        // Writes an unsigned 32bit int to the stream
        void WriteUInt32(uint32_t val) { Write<uint32_t>(val); }
        // Writes a signed 64bit int to the stream
        void WriteInt64(int64_t val) { Write<int64_t>(val); }
        // Writes an unsigned 64bit int to the stream
        void WriteUInt64(uint64_t val) { Write<uint64_t>(val); }
        // Writes a single precision float to the stream
        void WriteFloat(float val) { Write<float>(val); }
        // Writes a double precision float to the stream
        void WriteDouble(double val) { Write<double>(val); }
        // Writes a struct/type to the stream of the given type
        template <class T>
        void Write(T value)
        {
            if (Stream)
            {
                Stream.write((char*)&value, sizeof(T));
                return;
            }

            throw std::exception("Stream is closed");
        }
        // Writes bytes to the stream
        void WriteBytes(char* bytes, size_t count)
        {
            Stream.write(bytes, count);
        }
        // Writes a string terminated by a null byte
        void WriteNullTerminatedString(std::string value)
        {
            Stream.write(value.c_str(), value.length() + 1);
        }
        // Writes a string terminated by a null byte
        void WriteNullTerminatedString(std::wstring value)
        {
            Stream.write((char*)value.c_str(), (value.length() * 2) + 1);
        }
        // Seeks to the position in the stream
        void Seek(std::streamoff offset, SeekOrigin origin)
        {
            Stream.seekp(offset,
                origin == SeekOrigin::Begin ? std::ios::beg :
                origin == SeekOrigin::End ? std::ios::end : std::ios::cur);
        }
        // Gets the current stream position
        size_t GetPosition()
        {
            return (size_t)Stream.tellp();
        }
    };
}