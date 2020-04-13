#pragma once
#include "pch.h"

namespace PLX
{
    class Vector2
    {
    public:
        // X Value
        float X;
        // Y Value
        float Y;

        // Creates a new 2 Dimensional Vector at 0
        Vector2() : X(0), Y(0) {}
        // Creates a new 2 Dimensional Vector with the given values
        Vector2(float x, float y) : X(x), Y(y) {}
        // Adds the value to this vector
        Vector2 operator+(const Vector2 value) const
        {
            return Vector2(
                X + value.X,
                Y + value.Y);
        }
        // Adds the value to this vector
        Vector2 operator+(const float value) const
        {
            return Vector2(
                X + value,
                Y + value);
        }
        // Adds the value to this vector
        Vector2& operator+=(const Vector2& value)
        {
            X += value.X;
            Y += value.Y;
            return *this;
        }
        // Adds the value to this vector
        Vector2& operator+=(const float& value)
        {
            X += value;
            Y += value;
            return *this;
        }

        // Subtracts the value from this vector
        Vector2 operator-(const Vector2 value) const
        {
            return Vector2(
                X - value.X,
                Y - value.Y);
        }
        // Subtracts the value from this vector
        Vector2 operator-(const float value) const
        {
            return Vector2(
                X - value,
                Y - value);
        }
        // Subtracts the value from this vector
        Vector2& operator-=(const Vector2& value)
        {
            X -= value.X;
            Y -= value.Y;
            return *this;
        }
        // Subtracts the value from this vector
        Vector2& operator-=(const float& value)
        {
            X -= value;
            Y -= value;
            return *this;
        }
        // Negates the Vector
        Vector2 operator-() const
        {
            return Vector2(-X, -Y);
        }

        // Multiplies the value to this vector
        Vector2 operator*(const Vector2 value) const
        {
            return Vector2(
                X * value.X,
                Y * value.Y);
        }
        // Multiplies the value to this vector
        Vector2 operator*(const float value) const
        {
            return Vector2(
                X * value,
                Y * value);
        }
        // Multiplies the value to this vector
        Vector2& operator*=(const Vector2& value)
        {
            X *= value.X;
            Y *= value.Y;
            return *this;
        }
        // Multiplies the value to this vector
        Vector2& operator*=(const float& value)
        {
            X *= value;
            Y *= value;
            return *this;
        }

        // Divides the value from this vector
        Vector2 operator/(const Vector2 value) const
        {
            return Vector2(
                X / value.X,
                Y / value.Y);
        }
        // Divides the value from this vector
        Vector2 operator/(const float value) const
        {
            return Vector2(
                X / value,
                Y / value);
        }
        // Divides the value from this vector
        Vector2& operator/=(const Vector2& value)
        {
            X /= value.X;
            Y /= value.Y;
            return *this;
        }
        // Divides the value from this vector
        Vector2& operator/=(const float& value)
        {
            X /= value;
            Y /= value;
            return *this;
        }

        // Compares the 2 vectors for equality
        bool operator==(const Vector2 value) const
        {
            return (
                std::abs(X - value.X) < std::numeric_limits<float>::epsilon() &&
                std::abs(Y - value.Y) < std::numeric_limits<float>::epsilon()
                );
        }
        // Compares the Vector against the float for equality
        bool operator==(const float value) const
        {
            return (
                std::abs(X - value) < std::numeric_limits<float>::epsilon() &&
                std::abs(Y - value) < std::numeric_limits<float>::epsilon()
                );
        }
        // Compares the 2 Vectors for inequality
        bool operator!=(const Vector2 value) const
        {
            return !(*this == value);
        }
        // Compares the Vectors against the float for inequality
        bool operator!=(const float value) const
        {
            return !(*this == value);
        }
        // Outputs the vector to a stream
        std::ostream& operator<<(std::ostream& os)
        {
            return os << "(" << X << ", " << Y << ")";
        }
        // Gets a vector at 0
        const static Vector2 Zero()
        {
            return Vector2();
        }
    };
    class Vector3
    {
    public:
        // X Value
        float X;
        // Y Value
        float Y;
        // Z Value
        float Z;

        // Creates a new 3 Dimensional Vector at 0
        Vector3() : X(0), Y(0), Z(0) {}
        // Creates a new 3 Dimensional Vector with the given values
        Vector3(float x, float y, float z) : X(x), Y(y), Z(z) {}
        // Adds the value to this vector
        Vector3 operator+(const Vector3 value) const
        {
            return Vector3(
                X + value.X,
                Y + value.Y,
                Z + value.Z);
        }
        // Adds the value to this vector
        Vector3 operator+(const float value) const
        {
            return Vector3(
                X + value,
                Y + value,
                Z + value);
        }
        // Adds the value to this vector
        Vector3& operator+=(const Vector3& value)
        {
            X += value.X;
            Y += value.Y;
            Z += value.Z;
            return *this;
        }
        // Adds the value to this vector
        Vector3& operator+=(const float& value)
        {
            X += value;
            Y += value;
            Z += value;
            return *this;
        }

        // Subtracts the value from this vector
        Vector3 operator-(const Vector3 value) const
        {
            return Vector3(
                X - value.X,
                Y - value.Y,
                Z - value.Z);
        }
        // Subtracts the value from this vector
        Vector3 operator-(const float value) const
        {
            return Vector3(
                X - value,
                Y - value,
                Z - value);
        }
        // Subtracts the value from this vector
        Vector3& operator-=(const Vector3& value)
        {
            X -= value.X;
            Y -= value.Y;
            Z -= value.Z;
            return *this;
        }
        // Subtracts the value from this vector
        Vector3& operator-=(const float& value)
        {
            X -= value;
            Y -= value;
            Z -= value;
            return *this;
        }
        // Negates the Vector
        Vector3 operator-() const
        {
            return Vector3(-X, -Y, -Z);
        }

        // Multiplies the value to this vector
        Vector3 operator*(const Vector3 value) const
        {
            return Vector3(
                X * value.X,
                Y * value.Y,
                Z * value.Z);
        }
        // Multiplies the value to this vector
        Vector3 operator*(const float value) const
        {
            return Vector3(
                X * value,
                Y * value,
                Z * value);
        }
        // Multiplies the value to this vector
        Vector3& operator*=(const Vector3& value)
        {
            X *= value.X;
            Y *= value.Y;
            Z *= value.Z;
            return *this;
        }
        // Multiplies the value to this vector
        Vector3& operator*=(const float& value)
        {
            X *= value;
            Y *= value;
            Z *= value;
            return *this;
        }

        // Divides the value from this vector
        Vector3 operator/(const Vector3 value) const
        {
            return Vector3(
                X / value.X,
                Y / value.Y,
                Z / value.Z);
        }
        // Divides the value from this vector
        Vector3 operator/(const float value) const
        {
            return Vector3(
                X / value,
                Y / value,
                Z / value);
        }
        // Divides the value from this vector
        Vector3& operator/=(const Vector3& value)
        {
            X /= value.X;
            Y /= value.Y;
            Z /= value.Z;
            return *this;
        }
        // Divides the value from this vector
        Vector3& operator/=(const float& value)
        {
            X /= value;
            Y /= value;
            Z /= value;
            return *this;
        }

        // Compares the 2 vectors for equality
        bool operator==(const Vector3 value) const
        {
            return (
                std::abs(X - value.X) < std::numeric_limits<float>::epsilon() &&
                std::abs(Y - value.Y) < std::numeric_limits<float>::epsilon() &&
                std::abs(Z - value.Z) < std::numeric_limits<float>::epsilon()
                );
        }
        // Compares the Vector against the float for equality
        bool operator==(const float value) const
        {
            return (
                std::abs(X - value) < std::numeric_limits<float>::epsilon() &&
                std::abs(Y - value) < std::numeric_limits<float>::epsilon() &&
                std::abs(Z - value) < std::numeric_limits<float>::epsilon()
                );
        }
        // Compares the 2 Vectors for inequality
        bool operator!=(const Vector3 value) const
        {
            return !(*this == value);
        }
        // Compares the Vectors against the float for inequality
        bool operator!=(const float value) const
        {
            return !(*this == value);
        }
        // Outputs the vector to a stream
        std::ostream& operator<<(std::ostream& os)
        {
            return os << "(" << X << ", " << Y << ", " << Z << ")";
        }
        // Gets a vector at 0
        const static Vector3 Zero()
        {
            return Vector3();
        }
    };
    class Vector4
    {
    public:
        // X Value
        float X;
        // Y Value
        float Y;
        // Z Value
        float Z;
        // W Value
        float W;

        // Creates a new 4 Dimensional Vector at 0
        Vector4() : X(0), Y(0), Z(0), W(0) {}
        // Creates a new 4 Dimensional Vector with the given values
        Vector4(float x, float y, float z, float w) : X(x), Y(y), Z(z), W(w) {}
        // Adds the value to this vector
        Vector4 operator+(const Vector4 value) const
        {
            return Vector4(
                X + value.X,
                Y + value.Y,
                Z + value.Z,
                W + value.W);
        }
        // Adds the value to this vector
        Vector4 operator+(const float value) const
        {
            return Vector4(
                X + value,
                Y + value,
                Z + value,
                W + value);
        }
        // Adds the value to this vector
        Vector4& operator+=(const Vector4& value)
        {
            X += value.X;
            Y += value.Y;
            Z += value.Z;
            W += value.W;
            return *this;
        }
        // Adds the value to this vector
        Vector4& operator+=(const float& value)
        {
            X += value;
            Y += value;
            Z += value;
            W += value;
            return *this;
        }

        // Subtracts the value from this vector
        Vector4 operator-(const Vector4 value) const
        {
            return Vector4(
                X - value.X,
                Y - value.Y,
                Z - value.Z,
                W - value.W);
        }
        // Subtracts the value from this vector
        Vector4 operator-(const float value) const
        {
            return Vector4(
                X - value,
                Y - value,
                Z - value,
                W - value);
        }
        // Subtracts the value from this vector
        Vector4& operator-=(const Vector4& value)
        {
            X -= value.X;
            Y -= value.Y;
            Z -= value.Z;
            W -= value.W;
            return *this;
        }
        // Subtracts the value from this vector
        Vector4& operator-=(const float& value)
        {
            X -= value;
            Y -= value;
            Z -= value;
            W -= value;
            return *this;
        }
        // Negates the Vector
        Vector4 operator-() const
        {
            return Vector4(-X, -Y, -Z, -W);
        }

        // Multiplies the value to this vector
        Vector4 operator*(const Vector4 value) const
        {
            return Vector4(
                X * value.X,
                Y * value.Y,
                Z * value.Z,
                W * value.W);
        }
        // Multiplies the value to this vector
        Vector4 operator*(const float value) const
        {
            return Vector4(
                X * value,
                Y * value,
                Z * value,
                W * value);
        }
        // Multiplies the value to this vector
        Vector4& operator*=(const Vector4& value)
        {
            X *= value.X;
            Y *= value.Y;
            Z *= value.Z;
            W *= value.W;
            return *this;
        }
        // Multiplies the value to this vector
        Vector4& operator*=(const float& value)
        {
            X *= value;
            Y *= value;
            Z *= value;
            W *= value;
            return *this;
        }

        // Divides the value from this vector
        Vector4 operator/(const Vector4 value) const
        {
            return Vector4(
                X / value.X,
                Y / value.Y,
                Z / value.Z,
                W / value.W);
        }
        // Divides the value from this vector
        Vector4 operator/(const float value) const
        {
            return Vector4(
                X / value,
                Y / value,
                Z / value,
                W / value);
        }
        // Divides the value from this vector
        Vector4& operator/=(const Vector4& value)
        {
            X /= value.X;
            Y /= value.Y;
            Z /= value.Z;
            W /= value.W;
            return *this;
        }
        // Divides the value from this vector
        Vector4& operator/=(const float& value)
        {
            X /= value;
            Y /= value;
            Z /= value;
            W /= value;
            return *this;
        }

        // Compares the 2 vectors for equality
        bool operator==(const Vector4 value) const
        {
            return (
                std::abs(X - value.X) < std::numeric_limits<float>::epsilon() &&
                std::abs(Y - value.Y) < std::numeric_limits<float>::epsilon() &&
                std::abs(Z - value.Z) < std::numeric_limits<float>::epsilon() &&
                std::abs(W - value.W) < std::numeric_limits<float>::epsilon()
                );
        }
        // Compares the Vector against the float for equality
        bool operator==(const float value) const
        {
            return (
                std::abs(X - value) < std::numeric_limits<float>::epsilon() &&
                std::abs(Y - value) < std::numeric_limits<float>::epsilon() &&
                std::abs(Z - value) < std::numeric_limits<float>::epsilon() &&
                std::abs(W - value) < std::numeric_limits<float>::epsilon()
                );
        }
        // Compares the 2 Vectors for inequality
        bool operator!=(const Vector4 value) const
        {
            return !(*this == value);
        }
        // Compares the Vectors against the float for inequality
        bool operator!=(const float value) const
        {
            return !(*this == value);
        }
        // Outputs the vector to a stream
        std::ostream& operator<<(std::ostream& os)
        {
            return os << "(" << X << ", " << Y << ", " << Z << ", " << W << ")";
        }
        // Gets a vector at 0
        const static Vector4 Zero()
        {
            return Vector4();
        }
    };
}