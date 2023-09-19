cmake_minimum_required(VERSION 3.24)
project(Seminar4_911)

set(CMAKE_CXX_STANDARD 14)

include_directories(Playlist)

add_executable(Seminar4_911
        Playlist/main.cpp
        Playlist/PlayList.cpp
        Playlist/PlayList.h
        Playlist/Repository.cpp
        Playlist/Repository.h
        Playlist/RepositoryExceptions.cpp
        Playlist/RepositoryExceptions.h
        Playlist/Service.cpp
        Playlist/Service.h
        Playlist/Song.cpp
        Playlist/Song.h
        Playlist/UI.cpp
        Playlist/UI.h
        Playlist/Utils.cpp
        Playlist/Utils.h Playlist/FilePlayList.h Playlist/FilePlayList.cpp Playlist/CSVPlayList.h Playlist/CSVPlayList.cpp Playlist/SongException.h Playlist/SongException.cpp Playlist/SongValidator.h Playlist/SongValidator.cpp)
