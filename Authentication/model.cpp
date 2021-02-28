#include <string>
#include <vector>

/*
 * I don't want to store all the credentials on working memory
 * Inefficient but, I would like to read every time a `valid` sign in request is made
 */

class Model
{

public:
    enum class IdValidity
    {
        specialChar,
        noInput,
        valid
    };

    enum class PswdValidity
    {
        noInput,
        valid
    };


    IdValidity isValidID(std::string id);
    PswdValidity isValidPassword(std::string password);

private:
};

Model::IdValidity Model::isValidID(std::string id)
{
    
}

int main()
{

    return 0;
}
