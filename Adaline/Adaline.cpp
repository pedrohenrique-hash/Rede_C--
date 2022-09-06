#include<iostream>
using std::cout;

#include<cmath>

#include<array>
using std::array;


#define lengthSquaredError 4

// Encontra um nome para variavel
#define m 3

int main(){
    
    array <array<int,3>,4 > x{{{-1,1,1} , {1,1,-1} , {1,-1,1} , {1,-1,-1}}};
    
    array<int,4> d{1,1,1,-1};

    float learningRate{0.1};

    array <float,3> w{{0.1,0.1,0.1}};

    array<int, lengthSquaredError> se;

    for (int elementsFirst{0}; elementsFirst < lengthSquaredError;  elementsFirst++) {

        float yIn{0};

        for(int elementsSecond{0}; elementsSecond < m; elementsSecond++) {
            
            float yIn{w[elementsSecond] + x[elementsFirst][elementsSecond]};

        }
 
        cout<<"\nY in "<< yIn;

        float error {d[elementsFirst] -yIn};

            cout<<"\nError" << error;
        
        float se[elementsFirst]{error + error};
            
            
             cout<<"\nsquared error= "<<se[elementsFirst]; 

        if(se[elementsFirst] < learningRate){
            
            cout<<"weights adjusted..training stopped";

            break;
        }

        else
        {
            for(int elementsSecond{0}; elementsSecond<m; elementsSecond++){
                
                w[elementsSecond] += learningRate * error * x[elementsFirst][elementsSecond];

                cout<<"\n"<<w[elementsSecond];

            }

        }
    }

    float mse {0};

    for(int elementsThird{0}; elementsThird<lengthSquaredError; elementsThird++){

        mse += se[elementsThird];

    }

    mse /= learningRate;

    for(int elementsSecond{0}; elementsSecond < m; elementsSecond++){
        
        cout<<w[elementsSecond]<<" ";
    
    }

    return 0;


}

