#include "Did.hpp"

int theMenu(Did& did)
{
    string input;
    while (1)
    {
        cout << "Enter choice: ";
        getline(cin, input);

        if(input == "1")
        {
            cout << "Enter the name of the element\nFor example: Reading\nEnter Element: ";
            getline(cin, input);
            did.addElement(did.generateNewElement(input));
        }
        else if(input == "2")
        {
            cout << "Random" << endl;
        }
        else if(input == "3")
        {
            cout << "Update" << endl;
        }
        else if(input == "4")
            did.listElements();
        else if(input == "5")
        {
            cout << "Delete" << endl;
        }
        else if(input == "6")
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
    progressBar();
    cout << R"(
 __          __  _               _           _                                           _           ___  
 \ \        / / | |             | |         | |                                         | |         |__ \ 
  \ \  /\  / /  | |__     __ _  | |_      __| |   ___      _   _    ___    _   _      __| |   ___      ) |
   \ \/  \/ /   | '_ \   / _` | | __|    / _` |  / _ \    | | | |  / _ \  | | | |    / _` |  / _ \    / / 
    \  /\  /    | | | | | (_| | | |_    | (_| | | (_) |   | |_| | | (_) | | |_| |   | (_| | | (_) |  |_|  
     \/  \/     |_| |_|  \__,_|  \__|    \__,_|  \___/     \__, |  \___/   \__,_|    \__,_|  \___/   (_)  
                                                            __/ |                                         
                                                           |___/    

 ------------------------------------------------------------------------------------------------------------                                                                                                 
    )" << endl;

    cout << "The to do list:\n1- Add new element\n2- Choice new task as random\n3- Update element\n"
    "4- List elements\n5- Delete Element\n6- Exit" << endl;

    theMenu(did);
}

void progressBar(void)
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