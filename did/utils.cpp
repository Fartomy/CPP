#include "Did.hpp"

int theMenu(Did& did)
{
    string input;
    while (1)
    {
        cout << "[MENU] Enter choice: ";
        getline(cin, input);
        if(input == "0")
        {
                cout << "The Menu:\n0- Display the menu\n1- Add new element\n2- Choice new task as random\n3- Update element\n"
                "4- List elements\n5- Delete Element\n6- Display current task\n7- Exit" << endl;
        }
        else if(input == "1")
        {
            cout << "Enter the name of the element\nFor example: Reading\nEnter Element: ";
            getline(cin, input);
            did.addElement(did.generateNewElement(input));
        }
        else if(input == "2")
            did.randomHaveGetTask();
        else if(input == "3")
        {
            cout << "[Menu-3] Select your progress:\n1- Element operations\n2- Complete the task" << endl;
            while(1)
            {
                cout << "[Menu-3] Enter choice: ";
                getline(cin, input);
                if(input == "1")
                {
                    cout << "[Menu-3.1] Element operations:\n1- Edit element or material\n"
                    "2- Add a material into element" << endl;
                    input.clear();
                    while(1)
                    {
                        cout << "[Menu-3.1] Enter choice: ";
                        getline(cin, input);
                        if(input == "1")
                        {
                            cout << "[Menu-3.1.1] Enter the name of the element\nFor example: 'Reading'\n"
                            "[Menu-3.1.1] Enter element name: ";
                            getline(cin, input);
                            did.editElement(input);
                            break;
                        }
                        else if(input == "2")
                        {
                            cout << "[Menu-3.1.2] Enter element name: ";
                            getline(cin, input);
                            string elementName = input;
                            input.clear();
                            cout << "[Menu-3.1.2] Enter a new material name: ";
                            getline(cin, input);
                            did.addElementMaterial(elementName, input);
                            break;
                        }
                        else
                        {
                            cout << "Wrong input!" << endl;
                            input.clear();
                        }
                    }
                    break;
                }
                else if(input == "2")
                {
                    did.completeTask();
                    break;
                }
                else
                {
                    cout << "Wrong input!" << endl;
                    input.clear();
                }
            }
        }
        else if(input == "4")
            did.listElements();
        else if(input == "5")
        {
            cout << "Delete" << endl;
        }
        else if(input == "6")
           did.displayCurrentTask();
        else if(input == "7")
        {
            cout << R"(
 ________  ________  ________  ________          ___       ___  ___  ________  ___  __    ___       
|\   ____\|\   __  \|\   __  \|\   ___ \        |\  \     |\  \|\  \|\   ____\|\  \|\  \ |\  \      
\ \  \___|\ \  \|\  \ \  \|\  \ \  \_|\ \       \ \  \    \ \  \\\  \ \  \___|\ \  \/  /|\ \  \     
 \ \  \  __\ \  \\\  \ \  \\\  \ \  \ \\ \       \ \  \    \ \  \\\  \ \  \    \ \   ___  \ \  \    
  \ \  \|\  \ \  \\\  \ \  \\\  \ \  \_\\ \       \ \  \____\ \  \\\  \ \  \____\ \  \\ \  \ \__\   
   \ \_______\ \_______\ \_______\ \_______\       \ \_______\ \_______\ \_______\ \__\\ \__\|__|   
    \|_______|\|_______|\|_______|\|_______|        \|_______|\|_______|\|_______|\|__| \|__|   ___ 
                                                                                               |\__\
                                                                                               \|__|
            )" << endl;
            return 0;
        }
        else
        {
            cout << "Wrong input!" << endl;
            input.clear();
        }
        input.clear();
    }
    return 0;
}

void welcome(Did& did)
{
        cout << R"(
******************************************************************************
/*                                                                          */
/*                                                                          */
/*                                                                          */
/*  __          ___           _         _         _____       _      ___    */
/*  \ \        / / |         | |       | |       |_   _|     | |    |__ \   */
/*   \ \  /\  / /| |__   __ _| |_    __| | ___     | |     __| | ___   ) |  */
/*    \ \/  \/ / | '_ \ / _` | __|  / _` |/ _ \    | |    / _` |/ _ \ / /   */
/*     \  /\  /  | | | | (_| | |_  | (_| | (_) |  _| |_  | (_| | (_) |_|    */
/*      \/  \/   |_| |_|\__,_|\__|  \__,_|\___/  |_____|  \__,_|\___/(_)    */
/*                                                                          */       
/*                                                                          */
/*                                                                          */
/*                                                   It's just a helper..   */
******************************************************************************
    )" << endl;
    progressBarEffc();
    cout << R"(
 __          __  _               _           _                                           _           ___  
 \ \        / / | |             | |         | |                                         | |         |__ \ 
  \ \  /\  / /  | |__     __ _  | |_      __| |   ___      _   _    ___    _   _      __| |   ___      ) |
   \ \/  \/ /   | '_ \   / _` | | __|    / _` |  / _ \    | | | |  / _ \  | | | |    / _` |  / _ \    / / 
    \  /\  /    | | | | | (_| | | |_    | (_| | | (_) |   | |_| | | (_) | | |_| |   | (_| | | (_) |  |_|  
     \/  \/     |_| |_|  \__,_|  \__|    \__,_|  \___/     \__, |  \___/   \__,_|    \__,_|  \___/   (_)  
                                                            __/ |                                         
                                                           |___/

Rules:
2- Don't fool yourself  
1- After finishing a task, that task cannot be done again until all other tasks are completed
3- Don't deceive yourself                                                            

 ------------------------------------------------------------------------------------------------------------                                                                                                 
    )" << endl;

    cout << "The Menu:\n0- Display the menu\n1- Add new element\n2- Choice new task as random\n3- Update element\n"
    "4- List elements\n5- Delete Element\n6- Display current task\n7- Exit" << endl;

    theMenu(did);
}

void progressBarEffc(void)
{
    const int totalSteps = 10;
    for (int i = 0; i <= totalSteps; ++i) {
        float progress = static_cast<float>(i) / totalSteps;
        int barWidth = 75;
        int pos = static_cast<int>(barWidth * progress);

        cout << "[";
        for (int j = 0; j < barWidth; ++j)
            cout << (j < pos ? "=" : (j == pos ? ">" : " "));
        
        cout << "] " << int(progress * 100.0) << "% - Loading..\r";
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        cout.flush();
    }
    cout << "\nCompleted!" << endl;
}

void diceRollEffc()
{
    int durationInSeconds = 3;
    std::cout << "Rolling dice.." << std::endl;
    std::cout << '-' << std::flush;
    
    auto startTime = std::chrono::steady_clock::now();
    
    while (1) {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        std::cout << "\b\\" << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        std::cout << "\b|" << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        std::cout << "\b/" << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        std::cout << "\b-" << std::flush;
        
        auto currentTime = std::chrono::steady_clock::now();
        auto elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(currentTime - startTime).count();
        
        if (elapsedTime >= durationInSeconds) {
            break;
        }
    }   
    std::cout << std::endl;
}