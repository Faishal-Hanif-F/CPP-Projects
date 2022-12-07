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
                std::cout << "->";
                std::cin >> yes_or_no;
                std::cout << '\n';

                if ( yes_or_no == "1" ) 
                {
                    std::cout << "let us play\n\n";
                    this->startGame();

                } else if ( yes_or_no == "2" )
                {
                    std::cout << "cowards\n";
                }

           }
            
           
        }
        
        void startGame()
        {
            std::cout << "A crowd begins to gather, they can't wait to see some real\n";
            std::cout << "justice. There's just one thing, you aren't a real criminal.\n";
            std::cout << "No, no. You're the wrong time, wrong place type. You may think\n";
            std::cout << "you're dead, but it's not like that at all. Yes, yes. You've\n";
            std::cout << "got a chance to live. All you've gotta do is guess the right\n";
            std::cout << "words and you can live to see another day. But don't get so\n";
            std::cout << "happy yet. If you make 6 wrong guess, YOU'RE TOAST! VAMANOS!\n";

            this->coreGame();
        }

        void coreGame()
        {
            std::string input{};
            
            while (guesses < 6)
            {
                std::cout << "guess a letter ->";
                std::cin >> input;
                std::cout << '\n';


                guesses += 1;
            }

        }


};



int main(){

    Hangman();

    return 0;
}





