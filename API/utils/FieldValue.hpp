/**
 * @file   FieldVValue.hpp
 * @author nhyarlathotep
 * @date   25/01/19.
 *
 * @brief  FieldVValue declaration.
 */

#pragma once

#include <vector>
#include <string>
#include <unordered_map>

#include "ZiExcept.hpp"

namespace ZiApi {
    /**
     * @brief Contains a generic value
     *
     * Usage example:
     * @code
     *
     * ZiApi::FieldValue::ValueList list;                               //a list
     * ZiApi::FieldValue::ValueArray array;                             //an array
     *
     * array["key"] = "Wololo";                                         //a string
     * array["bread"] = 666;                                            //an integer
     *
     * list.emplace_back("Hello");                                      //emplace a string
     * list.emplace_back(array);                                        //emplace the array in the list
     * list.emplace_back(true);                                         //emplace a boolean
     *
     * ZiApi::FieldValue value(list);                                   //set the list as value
     *
     *
     * std::cout << value.toString() << std::endl;                      //[Hello, [bread:666, key:Wololo], true]
     *
     * if (value.getValueType() == ZiApi::FieldValue::Type::LIST) {
     *     value.getList()[0] = 42.42;
     * }
     *
     * std::cout << value.toString() << std::endl;                      //[42.42, [bread:666, key:Wololo], true]
     * @endcode
     * @sa ValueList
     * @sa ValueArray
     */
    class FieldValue {
    public:
        /**
         * @brief Defines a list of FieldValue
         */
        using ValueList = std::vector<FieldValue>;

        /**
         * @brief Defines a map of FieldValue
         */
        using ValueArray = std::unordered_map<std::string, FieldValue>;

        /**
         * Value types
         */
        enum class Type {
            INT,    ///< The value is an integer
            BOOL,   ///< The value is a boolean
            DOUBLE, ///< The value is a double
            STRING, ///< The value is a string
            LIST,   ///< The value is a list
            ARRAY,  ///< The value is an array
            NONE    ///< The value is unknown
        };

        /**
         * @brief The contained value
         */
        union ValueType {
            int intValue;
            bool boolValue;
            double doubleValue;
            std::string *stringValue;
            ValueList *listValue;
            ValueArray *arrayValue;
        };

        /**
         * @brief Default ctor, build a NONE type
         */
        FieldValue() : _type(Type::NONE) {};

        /**
         * @brief Create a FieldValue with an integer
         */
        explicit FieldValue(int value) : _type(Type::INT) { _value.intValue = value; }

        /**
         * @brief Create a FieldValue with a boolean
         */
        explicit FieldValue(bool value) : _type(Type::BOOL) { _value.boolValue = value; }

        /**
         * @brief Create a FieldValue with a double
         */
        explicit FieldValue(double value) : _type(Type::DOUBLE) { _value.doubleValue = value; }

        /**
         * @brief Create a FieldValue with a string
         */
        explicit FieldValue(const char *value) : _type(Type::STRING) { _value.stringValue = new std::string(value); }

        /**
         * @brief Create a FieldValue with a string
         */
        explicit FieldValue(const std::string &value) : _type(Type::STRING) { _value.stringValue = new std::string(value); }

        /**
         * @brief Create a FieldValue with a list
         */
        explicit FieldValue(const ValueList &value) : _type(Type::LIST) { _value.listValue = new ValueList(value); }

        /**
         * @brief Create a FieldValue with an array
         */
        explicit FieldValue(const ValueArray &value) : _type(Type::ARRAY) { _value.arrayValue = new ValueArray(value); }

        /**
         * @brief Copy ctor, build a FieldValue with an other
         */
        FieldValue(const FieldValue &other) : _type(other._type) {
            if (_type == Type::STRING)
                _value.stringValue = new std::string(*other._value.stringValue);
            else if (_type == Type::LIST)
                _value.listValue = new ValueList(*other._value.listValue);
            else if (_type == Type::ARRAY)
                _value.arrayValue = new ValueArray(*other._value.arrayValue);
            else
                _value = other._value;
        }

        ~FieldValue() {
            deleteValues();
        }

        FieldValue &operator=(int value) {
            deleteValues();
            _type = Type::INT;
            _value.intValue = value;
            return *this;
        }

        FieldValue &operator=(bool value) {
            deleteValues();
            _type = Type::BOOL;
            _value.boolValue = value;
            return *this;
        }

        FieldValue &operator=(double value) {
            deleteValues();
            _type = Type::DOUBLE;
            _value.doubleValue = value;
            return *this;
        }

        FieldValue &operator=(const char *value) {
            deleteValues();
            _type = Type::STRING;
            _value.stringValue = new std::string(value);
            return *this;
        }

        FieldValue &operator=(const std::string &value) {
            deleteValues();
            _type = Type::STRING;
            _value.stringValue = new std::string(value);
            return *this;
        }

        FieldValue &operator=(const ValueList &value) {
            deleteValues();
            _type = Type::LIST;
            _value.listValue = new ValueList(value);
            return *this;
        }

        FieldValue &operator=(const ValueArray &value) {
            deleteValues();
            _type = Type::ARRAY;
            _value.arrayValue = new ValueArray(value);
            return *this;
        }

        /**
         * @brief Gets the contained value's type
         */
        Type getValueType() const noexcept { return _type; }

        /**
         * @brief Gets the contained value as an integer
         */
        int &getInt() {
            if (_type != Type::INT)
                throw ZiExcept("Field value is not an int");
            return _value.intValue;
        }

        /**
         * @brief Gets the contained value as a boolean
         */
        bool &getBool() {
            if (_type != Type::BOOL)
                throw ZiExcept("Field value is not a bool");
            return _value.boolValue;
        }

        /**
         * @brief Gets the contained value as a double
         */
        double &getDouble() {
            if (_type != Type::DOUBLE)
                throw ZiExcept("Field value is not a double");
            return _value.doubleValue;
        }

        /**
         * @brief Gets the contained value as a string
         */
        std::string &getString() {
            if (_type != Type::STRING)
                throw ZiExcept("Field value is not a string");
            return *_value.stringValue;

        }

        /**
         * @brief Gets the contained value as a list
         */
        ValueList &getList() {
            if (_type != Type::LIST)
                throw ZiExcept("Field value is not a list");
            return *_value.listValue;
        }

        /**
         * @brief Gets the contained value as an array
         */
        ValueArray &getArray() {
            if (_type != Type::ARRAY)
                throw ZiExcept("Field value is not an array");
            return *_value.arrayValue;
        }

        /**
         * @brief Serializes the contained value as a string
         */
        std::string toString() const {
            size_t i = 0;
            std::string display;
            switch (_type) {
                case Type::BOOL: return std::string((_value.boolValue) ? "true" : "false");
                case Type::INT: return std::to_string(_value.intValue);
                case Type::DOUBLE: return std::to_string(_value.doubleValue);
                case Type::STRING: return *(_value.stringValue);
                case Type::LIST:
                    display = "[";
                    for (auto &it : *_value.listValue)
                        display += it.toString() + ((i++ != (_value.listValue)->size() - 1) ? ", " : "");
                    return display + "]";
                case Type::ARRAY:
                    display = "[";
                    for (auto &it : *_value.arrayValue)
                        display += it.first + ":" + it.second.toString() + ((i++ != (_value.arrayValue)->size() - 1) ? ", " : "");
                    return display + "]";
                default:
                    throw ZiExcept("Unknown type");
            }
        }

    private:
        Type _type;
        ValueType _value{};

        void deleteValues() {
            if (_type == Type::STRING)
                delete _value.stringValue;
            else if (_type == Type::LIST)
                delete _value.listValue;
            else if (_type == Type::ARRAY)
                delete _value.arrayValue;
        }
    };
}