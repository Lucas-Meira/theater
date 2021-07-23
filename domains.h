#ifndef DOMAINS_H
#define DOMAINS_S

#include <cstdint>
#include <array>
#include <regex>

template <typename T>
class BaseDomain
{
protected:
    T _value;
    virtual void _validate(T value) = 0;

public:
    virtual void set(const T value) = 0;
    inline T get() const
    {
        return _value;
    };
};

class Capacity : public BaseDomain<uint16_t>
{
protected:
    void _validate(uint16_t value) override;

public:
    Capacity(uint16_t value)
    {
        set(value);
    }

    static constexpr std::array<const uint16_t, 5> VALID_VALUES{100, 200, 300, 400, 500};

    void set(uint16_t value) override;
};

class Role : public BaseDomain<std::string>
{
protected:
    void _validate(std::string value) override;

public:
    Role(std::string value)
    {
        set(value);
    }

    inline static const std::string VALID_VALUES[6]{"Actor", "Cenographist", "Figurinist", "Makeup Artist", "Sound Designer", "Lighting Designer"};

    void set(std::string value) override;
};

//CLASSIFICAÇÃO livre, 10, 12, 14, 16, 18

class Rating : public BaseDomain<std::string>
{
protected:
    void _validate(std::string value) override;

public:
    inline static const std::array<const std::string, 6> VALID_VALUES{"general", "10", "12", "14", "16", "18"};

    void set(std::string value) override;
};

class IdCode : public BaseDomain<std::string>
{
protected:
    bool _isRightPattern(std::string value);
    void _validate(std::string value) override;
    inline static const std::regex VALID_PATTERN{std::regex("^[a-zA-Z]{2}[0-9]{4}$")};

public:
    IdCode(std::string value)
    {
        set(value);
    }

    void set(std::string value) override;
};

class Date : public BaseDomain<std::string>
{
protected:
    bool _isRightPattern(std::string value);
    bool _isValidDate(std::string date);
    bool _isLeapYear(unsigned int year);
    void _validate(std::string value) override;

    inline static const std::regex VALID_PATTERN{std::regex("^(0[0-9]|1[0-9]|2[0-9]|3[01])/(0[1-9]|1[0-2])/([2-9][0-9]{3})$")};
    static constexpr uint8_t DAYS_PER_MONTH[]{0, 31, 28, 31, 30, 31, 31, 30, 31, 30, 31, 30, 31};

    unsigned int _day;
    unsigned int _month;
    unsigned int _year;

public:
    Date(std::string date)
    {
        set(date);
    }

    inline unsigned int getDay()
    {
        return _day;
    }

    inline unsigned int getMonth()
    {
        return _month;
    }

    inline unsigned int getYear()
    {
        return _year;
    }

    void set(std::string value) override;
};

class Email : public BaseDomain<std::string>
{
protected:
    void _validate(std::string value) override;
    bool _isPeriodSequence(std::string testedAddress);
    bool _isPeriodAtBeginningOrEnd(std::string testedAddress);
    bool _isValidPeriods(std::string testedAddress);
    bool _isRightPattern(std::string testedAddress);
    // TODO: CHECK MINIMUM NUMBER OF CHARACTERS
    inline static const std::regex VALID_PATTERN{std::regex("^([a-zA-Z0-9!#$%&'*+\\-/=?^_`{|}~.]{0,64})@([a-zA-Z0-9!#$%&'*+\\-/=?^_`{|}~.]{0,255})$")};

    std::string _local;
    std::string _domain;

public:
    Email(std::string address)
    {
        set(address);
    }

    inline std::string getLocal() const { return _local; };
    inline std::string getDomain() const { return _domain; };

    void set(std::string value) override;
};

/*
HORÁRIO HH:MM
Em HH tem-se indicação de horário : 00 a 23
Em MM tem-se indicação de minuto : 00, 15, 30, 45
MATRÍCULA Formato XXXXX
Cada X é dígito (0-9).
Não podem existir dígitos duplicados.
NOME 5 a 20 caracteres.
Cada caracter é letra (A-Z ou a-z), ponto (.) ou espaço em branco.
Ponto (.) é precedido por letra.
Não há espaços em branco em sequência.
Primeira letra de cada termo é letra maiúscula (A-Z).
SENHA Formato XXXXXXXX
Cada caractere X é letra (A-Z ou a-z), dígito (0-9) ou caractere especial.
São possíveis caracteres especiais ! @ # $ % & ?
Não existe caracter repetido.
Existe pelo menos uma letra (maiúscula ou minúscula), um dígito e um caractere especial.
TELEFONE Formato (XX)-YYYYYYYYY
XX é um dos seguintes códigos 11, 12, 13, 14, 15, 16, 17, 18, 19, 21, 22, 24, 27, 28, 32, 33,
34, 35, 37, 38, 41, 42, 43, 44, 45, 46, 47, 48, 49, 51, 53, 54, 55, 61, 62, 63, 64, 65, 66, 67, 68,
69, 71, 73, 74, 75, 77, 79, 81, 82, 83, 84, 85, 86, 87, 88, 89, 91, 92, 93, 94, 95, 96, 97, 98, 99.
Cada Y é dígito (0-9).
Não existe número de telefone 000000000.
TIPO auto, comédia, drama, farsa, melodrama, monólogo, musical, ópera, revista
*/
#endif