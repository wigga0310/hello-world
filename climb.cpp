#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

//宣告&初始化

	int t = 0;       			//t = 步數
	double x = 0;               //x ＝ 傘兵降落之x座標
	double y = 0;	 			//y = f(x)值
	double y_total = 0; 		//計算平均最小值用
	double t_total = 0; 		//計算平均步數用
	double dist = 1.0;			//dist = 非變動大步距 
	double dist2 = 1.0;			//dist = 變動大步距 
	double ddist = 0.01;		//dist = 非變動小步距 
	double ddist2 = 0.01;		//dist = 變動小步距
	double arr[100];			//測資陣列

//step1 function setting
	double f(double x){
		if(x < 0){
			return -x;
		}else{
			return x;
		}
	}

//step2 climb function
	void climb(double x){		
		t = 0;								//重設步數	
		dist2 = 1;							//重設變動大步距
		ddist2 = 0.01;						//重設變動小步距
		
		while(1){
			if(f(x)>f(x+dist2)){			//變動大步距移動
				x = x + dist2;
				dist2++;
				t++;	
			}else if(f(x)>f(x-dist2)){
				x = x - dist2;
				dist2++;
				t++;
			}else if(f(x)>f(x+dist)){		//非變動大步距移動
				x = x + dist;
				t++;	
			}else if(f(x)>f(x-dist)){
				x = x - dist;
				t++;
			}else if(f(x)>f(x+ddist2)){		//變動小步距移動
				x = x + ddist2;
				ddist2 = ddist2 + 0.01;
				t++;	
			}else if(f(x)>f(x-ddist2)){
				x = x - ddist2;
				ddist2 = ddist2 + 0.01;
				t++;
			}else if(f(x)>f(x+ddist)){		//非變動小步距移動
				x = x + ddist;
				t++;	
			}else if(f(x)>f(x-ddist)){
				x = x - ddist;
				t++;
			}else{
				y = f(x);
				y_total = y_total + y;
				t_total = t_total + t;
				break;
			}
		}
	}

//step3 main
	int main(){

	//step4 random test data
		srand(114);

		for(int i=0;i<100;i++){
			arr[i] = ((double) rand() / (RAND_MAX))*200-100;
		}


		cout <<setfill(' ')<<setw(2)<< "回合" << "  " << "步數" << "    " << "最小值" << "       " << "起始點" << endl;

		for(int i=0;i<100;i++){
			x = arr[i];
			climb(x);
			cout << setfill(' ') << setw(3)<< i+1 ;
			cout << "     " ;
			cout << setfill(' ')<<setw(2)<< t ;
			cout << "     ";
			cout << fixed <<setprecision(4) << y ;
			cout << "     " ;
			cout << setprecision(4) << x<< endl ;
		}

		cout << "步數平均" << "  " << "最小值平均" << endl;
		cout << t_total /100 << "           " << y_total/100 << endl;
	}