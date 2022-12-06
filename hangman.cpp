#include <iostream>
#include <string>
#include <vector>

class Hangman {
    private:
        int guesses{};
        std::string letters_used{""};
        std::string the_word {"dimsum"};
        std::vector<std::string> progress {"?", "?", "?", "?", "?"};

    public:
        Hangman()
        {
           std::string yes_or_no{};

        // if the user input isn't 1 or 2, keep asking.
           while ( yes_or_no != "1" && yes_or_no != "2" ) 
           {
                std::cout << "Welcome to 'Hangman', are you ready to die?\n";
                std::cout << "(1)Yes, for i am already dead.\n(2)No, get me outta here!\n"; 
                std::cin >> yes_or_no;

                if ( yes_or_no == "1" ) 
                {
                    std::cout << "let us play\n";
                    this->startGame();

                } else if ( yes_or_no == "2" )
                {
                    std::cout << "cowards\n";
                }

           }
            
           
        }
        // startGame is roughly equal to core_game()
        void startGame()
        {
            printf("hello world");
        }
};



int main(){

    Hangman();

    return 0;
}





