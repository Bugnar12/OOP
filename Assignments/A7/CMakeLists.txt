cmake_minimum_required(VERSION 3.16)
project(a45_Bugnar12)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(a45_Bugnar12
        Domain/Domain.cpp
        Domain/Domain.h main.cpp Tests/Tests.h Tests/Tests.cpp Repositroy/AdminRepo.h Repositroy/AdminRepo.cpp Service/Services.h Service/Services.cpp "User Interface/UI.h" "User Interface/UI.cpp" Repositroy/UserRepo.h Repositroy/UserRepo.cpp Repositroy/CSV_Repository.h Repositroy/CSV_Repository.h Repositroy/CSV_Repository.cpp Repositroy/HTML_Repository.h Repositroy/HTML_Repository.cpp Validator/Exceptions.h Validator/Exceptions.cpp Validator/Validators.h Validator/Validators.cpp)
