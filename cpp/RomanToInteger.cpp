class Solution {
public:
    int romanToInt(string s) {
        int Integer = 0;
        bool c_flag = false;
        bool x_flag = false;
        bool i_flag = false;
        for(char c : s){
            std::cout<<c<<std::endl;
            if(c == 'M'){
                if(c_flag == true){
                    Integer += 800;
                    c_flag == false;
                    continue;
                }
                Integer += 1000;
            }
            if(c == 'D'){
                if(c_flag == true){
                    Integer += 300;
                    c_flag == false;
                    continue;
                }
                Integer += 500;
            }
            if(c == 'C'){ 
                if(x_flag == true){
                    Integer += 80;
                    x_flag == false;
                    continue;
                }
                c_flag = true;
                Integer += 100;
            }
            if(c == 'L'){
                if(x_flag == true){
                    Integer += 30;
                    x_flag == false;
                    continue;
                }
                Integer += 50;
            }
            if(c == 'X'){
                if(i_flag == true){
                    Integer += 8;
                    i_flag == false;
                    continue;
                }
                x_flag = true;
                Integer += 10;
            }
            if(c == 'V'){
                if(i_flag == true){
                    Integer += 3;
                    i_flag == false;
                    continue;
                }
                Integer += 5;
            }
            if(c == 'I'){
                i_flag = true;
                Integer += 1;
            }
        }

        
        return Integer;
    }
};