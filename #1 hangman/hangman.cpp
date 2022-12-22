#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>



class Hangman {
    private:
        int guesses{};
        // unfortunately cpp isn't as magical as python
        // so we'll be using an unordered_map instead of just string
        std::unordered_map<std::string, int> letters_used;
        std::string the_word {};
        std::string hint     {};

    public:
        Hangman()
        {
            std::string yes_or_no{};  

            std::vector<std::string> the_wordAndHints { askUserTheWord() };
            the_word = the_wordAndHints[0];
            hint = the_wordAndHints[1];
            
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
            
            std::cout << "\nhints:\n" << hint << std::endl;
            

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
                    progressUpdater(input, the_word);
                    showLettersUsed(letters_used);
                    
                    std::cin.ignore();
                    std::cin.get();
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
                    progressUpdater(input, the_word);
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
                             std::string the_word)
        {
            std::vector<int> resultIndex;

            std::string tempTarget{the_word};

            for (int i = 0; i < input.size(); i++)
            {
                if(tempTarget.find(input[i]) != std::string::npos)
                {
                    std::size_t p{tempTarget.find(input[i])};
                    resultIndex.push_back( p );
                    
                    tempTarget.replace(p, 1, ".");
                }
            }

            std::cout << "Progress: ";
            for (int i = 0; i < the_word.size(); i++)
            {
                // if input letters is inside the_word
                for (int j = 0; j < resultIndex.size(); j++)
                {
                    if(i == resultIndex[j])
                    {
                        std::cout << the_word[i] << " ";
                        i++;
                    }
                }
                if(i < the_word.size()) std::cout << "? ";
            }
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

        std::vector<std::string> askUserTheWord()
        {
            std::cout << std::endl;
            
            std::string              hint     {};
            std::string              line     {};
            std::string              the_word {};
            std::vector<std::string> result   {};

            std::cout << "write the_word to be guessed\n";
            std::cin  >> the_word;
            result.push_back(the_word);
            std::cin.ignore();

            std::cout << "write hints about the_word" << std::endl;
            while(true) 
            {
                std::getline(std::cin,line);
                if (line == "quit") break;
                hint.append(line+"\n");
                std::cout << "write \"quit\" to stop writing hints\n";
            }
            hint[hint.size()-1]='\0';

            result.push_back(hint);

            return result;
        }


};



int main(){

    Hangman();

    return 0;
}