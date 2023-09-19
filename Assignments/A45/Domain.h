#include <string>
#include <iostream>

class Domain {
private:
    std::string title;
    std::string genre;
    int releaseYear;
    int nrOfLikes; ///this is the "id" of the Movie object
    std::string trailer; ///this is the link to a video of the movie

public:
    Domain(); ///constructor
    Domain(const std::string &title, const std::string &genre,
            int releaseYear, int nrOfLikes, const std::string &trailer);



    std::string getTitle() const; ///all getters should be of type const
    std::string getGenre() const;
    int getReleaseYear() const;
    int getNrOfLikes() const;
    std::string getTrailer() const;

    std::string toStr();

    int play();

    Domain &operator=(const Domain &movie);
};

inline bool operator == (const Domain &movie1, const Domain &movie2)
{
    return movie1.getTrailer() == movie2.getTrailer();
}
