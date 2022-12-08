#include <iostream>
#include <vector>
#include <unordered_map>



class Hangman {
    private:
        int guesses{};
        // unfortunately cpp isn't as magical as python
        // so we'll be using an unordered_map instead of just string
        std::unordered_map<std::string, int> letters_used;
        std::string the_word {"amogus"};
        // progress contain each the_word letters
        std::unordered_multimap<std::string, std::string> progress{};

    public:
        Hangman()
        {
           std::string yes_or_no{};
           

           progress = turnTheWordIntoProgressBar(the_word);
           

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
                    startGame();

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

            coreGame();
        }

        void coreGame()
        {
            std::string input{};
            
            while (guesses < 6)
            {
                std::cout << "guess a letter ->";
                std::cin >> input;
                std::cout << '\n';
                
                
				// if input is equal the answer and hasn't been used, wins
                if (input == the_word && (letters_used.find(input) == letters_used.end()))
                {
                    std::cout << "As it turns out, your guess was RIGHT!\n";

                    letters_used.insert( {input, guesses} );

                    hangman_graphic(guesses);
                    progressUpdater(input, the_word, progress);
                    showLettersUsed(letters_used);
                    break;
                } 
                // input isn't the right answer and hasn't been used, guesses + 1  
                else if (input != the_word && (letters_used.find(input) == letters_used.end()))
                {
                    guesses += 1;

                    std::cout << "Things aren't looking so good, that guess was WRONG!\n"; 
                    std::cout << "Oh man, that crowd is getting happy, I thought you\n";
                    std::cout << "wanted to make them mad?\n";

                    letters_used.insert( {input, guesses} );

                    hangman_graphic(guesses);
                    progressUpdater(input, the_word, progress);
                    showLettersUsed(letters_used);
                } 
                // if input is already used, ask again
                else
                {
                    std::cout << "That's the wrong letter, you wanna be out here all day?\n";
				    std::cout << "Try again!\n";
                }
                
                
            }

        }

        void hangman_graphic(int guesses)
        {
            switch (guesses)
            {
                case 0:
                    std::cout << "________      \n";
                    std::cout << "|      |      \n";
                    std::cout << "|             \n";
                    std::cout << "|             \n";
                    std::cout << "|             \n";
                    std::cout << "|             \n";
                    break;
                case 1:
                    std::cout << "________      \n";
                    std::cout << "|      |      \n";
                    std::cout << "|      0      \n";
                    std::cout << "|             \n";
                    std::cout << "|             \n";
                    std::cout << "|             \n";
                    break;
                case 2:
                    std::cout << "________      \n";
                    std::cout << "|      |      \n";
                    std::cout << "|      0      \n";
                    std::cout << "|     /       \n";
                    std::cout << "|             \n";
                    std::cout << "|             \n";
                    break;
                case 3:
                    std::cout << "________      \n";
                    std::cout << "|      |      \n";
                    std::cout << "|      0      \n";
                    std::cout << "|     /|      \n";
                    std::cout << "|             \n";
                    std::cout << "|             \n";
                    break;
                case 4:
                // double backslash to escape the escape sequences
                    std::cout << "________      \n";
                    std::cout << "|      |      \n";
                    std::cout << "|      0      \n";
                    std::cout << "|     /|\\    \n";
                    std::cout << "|             \n";
                    std::cout << "|             \n";
                    break;
                case 5:
                // double backslash to escape the escape sequences
                    std::cout << "________      \n";
                    std::cout << "|      |      \n";
                    std::cout << "|      0      \n";
                    std::cout << "|     /|\\    \n";
                    std::cout << "|     /       \n";
                    std::cout << "|             \n";
                    break;
                default:
                // double backslash to escape the escape sequences
                    std::cout << "________      \n";
                    std::cout << "|      |      \n";
                    std::cout << "|      0      \n";
                    std::cout << "|     /|\\    \n";
                    std::cout << "|     / \\    \n";
                    std::cout << "|             \n";

                    std::cout << "The noose tightens around your neck, and you feel the\n";
                    std::cout << "sudden urge to urinate.\n";
                    std::cout << "GAME OVER!\n";
                    break;
            }
        }

        void progressUpdater(std::string input, 
                             std::string the_word, 
                             std::unordered_multimap<std::string, std::string> progress)
        {
            std::cout << "Progress: ";


            std::cout << std::endl;
        }

        void showLettersUsed(std::unordered_map<std::string, int> letters_used)
        {
            std::cout << "Letter used: ";
            
            for (auto i = letters_used.begin(); i != letters_used.end(); i++)
            {
                std::cout << i->first << ", ";
            }

            std::cout << std::endl;
            
        }

        // since multimap is sorted, how about putting numbers or
        // alphabet in front of the keys so it will be ordered correctly
        // example:
        // input "amogus"
        // output key - value
        // numerically
        // 1a - "?", 2m - "?", 3o - "?",.... , 6s - "?"
        // or
        // alphabetically
        // aa - "?", bm - "?", co - "?",.... , fs - "?"

        // if the progress bar is wrongly ordered fix it here.
        std::unordered_multimap<std::string, std::string> turnTheWordIntoProgressBar(std::string the_word)
        {
            std::unordered_multimap<std::string, std::string> result;
            std::string questionMark {"?"};
            std::string individualWords{};

            for (int i = 0; i < the_word.size(); i++)
            {
                individualWords = the_word[i];
                result.insert( {individualWords,  questionMark} );
            }

            for (auto i = progress.begin(); i != progress.end(); i++)
            {
                std::cout << i->first << " - ";
            }

            std::cout << std::endl;

            std::cout << std::endl;

            return result;
        }

};



int main(){

    Hangman();

    return 0;
}





