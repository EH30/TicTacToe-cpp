#include <iostream>

std::string board[3][3] = {{" ", " ", " "}, {" ", " ", " "}, {" ", " ", " "}};
int inout[2] = {0,0};


std::string valid_inputs[9] = {
    "a1", "a2", "a3", 
    "b1", "b2", "b3", 
    "c1", "c2", "c3"
};


int valid_output[9][2] = {
    {0,0}, {0,1}, {0,2},
    {1,0}, {1,1}, {1,2},
    {2,0}, {2,1}, {2,2}
};


void display(){
    std::cout << "  " << board[0][0] << "   |   " << board[0][1] << "  |   " << board[0][2] << "    " << std::endl;
    std::cout << "----------------------" << std::endl;
    std::cout << "  " << board[1][0] << "   |   " << board[1][1] << "  |   " << board[1][2] << "    " << std::endl;
    std::cout << "----------------------" << std::endl;
    std::cout << "  " << board[2][0] << "   |   " << board[2][1] << "  |   " << board[2][2] << "    " << std::endl;
}


void moves(std::string in){
    for (int x=0; x < sizeof(valid_inputs)/sizeof(valid_inputs[0]); x++){
        if (valid_inputs[x] == in){
            inout[0] = valid_output[x][0];
            inout[1] = valid_output[x][1];
            break;
        }
    }
}


bool check_valid(std::string in){
    for (int x=0; x< sizeof(valid_inputs)/sizeof(valid_inputs[0]); x++){
        if (valid_inputs[x] == in){
            return true;
        }
    }

    return false;
}


bool check_horizontal(){
    if (board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][0] != " "){
        return true;
    }else if (board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][0] != " "){
        return true;
    }else if (board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][0] != " "){
        return true;
    }else{
        return false;
    }
}


bool check_vertical(){
    if (board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[0][0] != " "){
        return true;
    }else if (board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[0][1] != " "){
        return true;
    }else if (board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[0][2] != " "){
        return true;
    }else{
        return false;
    }
}


bool check_corners(){
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != " "){
        return true;
    }else if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != " "){
        return true;
    }else{
        return false;
    }
}


bool check_full(){
    for (int x=0; x< sizeof(board)/sizeof(board[0]); x++){
        for (int i=0; i< sizeof(board)/sizeof(board[0]); i++){
            if (board[x][i] == " "){
                return false;
            }
        }
    }

    return true;
}


int main(int argc, char const** argv)
{
    int turn = 0;
    std::cout << "Moves: a1,a2,a3, b1,b2,b3, c1,c2,c3\n" << std::endl;

    
    while (1){
        std::string user_input;
        if (turn == 0){
            std::cout << "Player 1: ";
            std::cin >> user_input;
            turn = 1;
        }else {
            std::cout << "Player 2: ";
            std::cin >> user_input;
            turn = 0;
        }
        

        if (!check_valid(user_input)){
            std::cout << "That's not a valid option" << std::endl;
            continue;
        }

        moves(user_input);

        if (turn == 1){
            if (board[inout[0]][inout[1]] == " "){
                board[inout[0]][inout[1]] = "X";
            }else{
                std::cout << "That Place is Already Taken" << std::endl;
            }
        }else{
            if (board[inout[0]][inout[1]] == " "){
                board[inout[0]][inout[1]] = "O";
            }else{
                std::cout << "That Place is Already Taken" << std::endl;
            }
        }

        display();

        if (check_horizontal()){
            if (turn == 1){
                std::cout << "Winner: Player 1" << std::endl;
                break;
            }else{
                std::cout << "Winner: Player 2" << std::endl;
                break;
            }
        }else if (check_vertical()){
            if (turn == 1){
                std::cout << "Winner: Player 1" << std::endl;
                break;    
            }else{
                std::cout << "Winner: Player 2" << std::endl;
                break;
            }
        }else if (check_corners()){
            if (turn == 1){
                std::cout << "Winner: Player 1" << std::endl;
                break;
            }else{
                std::cout << "Winner: Player 2" << std::endl;
                break;
            }
        }

        if (check_full()){
            std::cout << "Game Ended in a Draw" << std::endl;
            break;
        }
    }

    system("sleep 10");
    return 0;
}
