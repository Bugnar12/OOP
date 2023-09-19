#ifndef A45_BUGNAR12_EXCEPTIONS_H
#define A45_BUGNAR12_EXCEPTIONS_H

#include <exception>

class OperationError : public std::exception{
private:
    const char *message;
public:
    OperationError(const char *message);
    const char *what() const noexcept override;
};

class FileError : public std::exception{
private:
    const char *message;
public:
    FileError(const char *message);
    const char *what() const noexcept override;

};

class InputError : public std::exception{
private:
    const char *message;
public:
    InputError(const char *message);
    const char *what() const noexcept override;
};


#endif //A45_BUGNAR12_EXCEPTIONS_H
