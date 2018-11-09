#include <iostream>
#include <string>
#include <cmath>
void interval_calculator();
int main();
int main(){
	interval_calculator();
	return 0;
}
void interval_calculator(){
	double a={1};
	double b={0};
	double ma={1};
	double mb={0};
	double ia={1};
	double ib={0};
	std::string command;
	do {
		std::cout << "input :>";
		std::cin >> command;
		if (!(command=="exit"||command=="enter"||command=="negate"||command=="invert"||command=="ms"||command=="mr"||command=="mc"||command=="m+"||command=="m-"||command=="scalar_add"||command=="scalar_subtract"||command=="scalar_multiply"||command=="scalar_divide"||command=="scalar_divided_by"||command=="interval_add"||
		command=="interval_subtract"||command=="interval_multiply"||command=="interval_divide"||command=="intersect"||command=="integers"||command=="cartesian_integers")){
			std::cout << "Error: illegal command" << std::endl;
		}
		
		if(command == "enter"){
				std::cin >> a >> b;
				ia=a;
				ib=b;
				if(a<=b){std::cout << "[" << a<< ", " << b << "]" << std::endl;}
				if(a>b){ std::cout << "Error: invalid interval as " << a << " > " << b << std::endl;
						std::cout << "--" << std::endl;
					}
				
		}
		if(command=="negate"){ 
			if(ia==1&&ib==0){
				std::cout << "--" << std::endl;
			}else{double part;
			part=ia;
			ia=-ib;
			ib=-part;
			std::cout << "[" << ia << ", " << ib << "]" << std::endl;
			}
		}
		if(command=="invert"){
			if(ia==1&&ib==0){
				std::cout << "--" << std::endl;
			}else if((ia<=0&&ib>0)||(ia==0&&ib==0)){
				std::cout << "Error: division by zero" << std::endl;
				std::cout << "--" << std::endl;
			}else{
				double part;
				part=ia;
				ia=1.0/ib;
				ib=1.0/part;
				std::cout << "[" << ia << ", " << ib << "]" << std::endl;
			}
		}
		if(command=="ms"){
			if(ia==1&&ib==0){
				std::cout << "--" << std::endl;
			}else{
			ma=ia;
			mb=ib;
			std::cout << "[" << ia << ", " << ib << "]" << std::endl;
			}
		}
		if(command=="mr"){ 
			if(ia==1&&ib==0){
				std::cout << "--" << std::endl;
			}else{	
			if(ma!=1&&mb!=0){
				std::cout << "[" << ma << ", " << mb << "]" << std::endl;
			}
			if(ma==1&&mb==0){
				std::cout << "[" << ia << ", " << ib << "]" << std::endl;
			}
			}
		}
		if(command=="mc"){
			if(ia==1&&ib==0){
				std::cout << "--" << std::endl;
			}else{
			ia = ma;
			ib = mb;
			ma=1;
			mb=0;	
			std::cout << "[" << ia << ", " << ib << "]" << std::endl;		
						}
		}
		if(command=="m+"){
				if (ia==1&&ib==0){
					std::cout << "--" << std::endl;
				}else{
					ma=ia;
					mb=ib;
					ma+=ia;
					mb+=ib;
					std::cout << "[" << ia << ", " << ib << "]" << std::endl;
				}
		}
		if(command=="m-"){
			if ((ia==1&&ib==0)||(ma==1&&mb==0)){
					std::cout << "--" << std::endl;
				}else{
				ma=ia;
				mb=ib;
				ma=-ia;
				mb=-ib;
				std::cout << "[" << ia << ", " << ib << "]" << std::endl;
			}
		}
		if(command=="scalar_add"){
			double c;
			std::cin >> c;
			if(ia==1&&ib==0){
				std::cout << "--" << std::endl;
			}else{
				ia=ia+c;
				ib=ib+c;
				std::cout << "[" << ia << ", " << ib << "]" << std::endl;
			}
		}
		if (command=="scalar_subtract"){
			double c;
			std::cin >> c;
			if(ia==1&&ib==0){
				std::cout << "--" << std::endl;
			}else{
				ia=ia-c;
				ib=ib-c;
				std::cout << "[" << ia << ", " << ib << "]" << std::endl;
			}
		}
		if (command=="scalar_multiply"){
			double c;
			std::cin >> c;
			if(ia==1&&ib==0){
			std::cout << "--" << std::endl;
			}else{
				if(c>0){
				ia=ia*c;
				ib=ib*c;
				std::cout << "[" << ia << ", " << ib << "]" << std::endl;	
				}
				if(c==0){
				ia=ia*0;
				ib=ib*0;
				std::cout << "[" << ia << ", " << ib << "]" << std::endl;
				}
				if(c<0){
				double part;
				part=ia;
				ia=ib*c;
				ib=part*c;
				std::cout << "[" << ia << ", " << ib << "]" << std::endl;
				}
			}
		} 
		if (command=="scalar_divide"){
			double c;
			std::cin >> c;
			if(ia==1&&ib==0){
			std::cout << "--" << std::endl;
			}else{
				if(c>0){
				ia=ia/c;
				ib=ib/c;
				std::cout << "[" << ia << ", " << ib << "]" << std::endl;	
				}
				if(c==0){
				std::cout << "Error: division by zero" << std::endl;
				std::cout << "--" << std::endl;
				}
				if(c<0){
				double part;
				part=ia;
				ia=ib/c;
				ib=part/c;
				std::cout << "[" << ia << ", " << ib << "]" << std::endl;
				}
			}
		}
		if (command=="scalar_divided_by"){
			double c;
			std::cin >> c;
			if(ia==1&&ib==0){
			std::cout << "--" << std::endl;
			}else{
				if(a<=0&&b>=0){
				std::cout << "Error: division by zero" << std::endl;
				std::cout << "--" << std::endl;	
				}
				else if(c>0){
				ia=c/ia;
				ib=c/ib;
				std::cout << "[" << ia << ", " << ib << "]" << std::endl;
				}
				else if(c<=0){
				double part;
				part=ia;
				ia=c/ib;
				ib=c/part;
				std::cout << "[" << ia << ", " << ib << "]" << std::endl;
				}
			}
		}
		if(command=="interval_add"){
			double c;
			double d;
			std::cin >> c >> d;
			if(c>d){
					std::cout << "Error: invalid interval as " << 	c << " > " << d << std::endl;
					std::cout << "[" << ia << ", " << ib << "]" << std::endl;
				}else if(ia==1&&ib==0){
					std::cout << "--" << std::endl;}
					else{
					ia=ia+c;
					ib=ib+d;
					std::cout << "[" << ia << ", " << ib << "]" << std::endl;
					}
		}
		if(command=="interval_subtract"){
			double c;
			double d;
			std::cin >> c >> d;
			if(c>d){
					std::cout << "Error: invalid interval as " << 	c << " > " << d << std::endl;
					std::cout << "--" << std::endl;
				}else if(ia==1&&ib==0){
					std::cout << "--" << std::endl;}
					else{
					ia=ia-d;
					ib=ib-c;
					std::cout << "[" << ia << ", " << ib << "]" << std::endl;
					}
		}
		if(command=="interval_multiply"){
			double c;
			double d;
			std::cin >> c >> d;
			if(c>d){
				std::cout << "Error: invalid interval as " << c << " > " << d << std::endl;
				std::cout << "--" << std::endl;
			}else if(ia==1&&ib==0){
			std::cout << "--" << std::endl;}
			else{
				double min[4]={ia*c,ia*d,ib*c,ib*d}; 
				double max[4]={ia*c,ia*d,ib*c,ib*d};
				for (int i=0; i<=2; i++){
					if(min[i]<=min[i+1]){
						min[i+1]=min[i];
					}
				}
				for (int i=0; i<=2; i++){
					if(max[i]>=max[i+1]){
						max[i+1]=max[i];
					}
				}
				ia=min[3];
				ib=max[3];
				std::cout <<  "[" << ia << ", " << ib << "]" << std::endl;
			
			}
		}
		if(command=="interval_divide"){
			double c;
			double d;
			std::cin >> c >> d;
			if(c>d){
				std::cout << "Error: invalid interval as " << c << " > " << d << std::endl;
				std::cout << "--" << std::endl;
			}else if(ia==1&&ib==0){
			std::cout << "--" << std::endl;}
			else if(c<=0&&d>=0){
				std::cout << "Error: division by zero " << std::endl;
				std::cout << "--" << std::endl;
			}
			else{
				double min[4]={ia/c,ia/d,ib/c,ib/d}; 
				double max[4]={ia/c,ia/d,ib/c,ib/d};
				for (int i=0; i<=2; i++){
					if(min[i]<=min[i+1]){
						min[i+1]=min[i];
					}
				}
				for (int i=0; i<=2; i++){
					if(max[i]>=max[i+1]){
						max[i+1]=max[i];
					}
				}
				ia=min[3];
				ib=max[3];
				std::cout <<  "[" << ia << ", " << ib << "]" << std::endl;
			
			}
		}
		//intersect
		if (command=="intersect"){
			double c;
			double d;
			std::cin >> c >> d;
			if(c>d){
				std::cout << "Error: invalid interval as " << c << " > " << d << std::endl;
				std::cout << "--" << std::endl;}
			else if(ia==1&&ib==0){
				std::cout << "--" << std::endl;}
			else{
				double L=std::max(ia,c);
				double R=std::min(ib,d);
				if(L<=R){
					ia=std::max(ia,c);
					ib=std::min(ib,d);
					std::cout <<  "[" << ia << ", " << ib << "]" << std::endl; 
				}else{
					std::cout << "--" << std::endl;
				}
			}
		}
		if (command=="integers"){
			int up=std::floor(ib);
			int low=std::ceil(ia);
			if(low<=up){
			for(int i=low;i<up;i++){
				std::cout << i << ", ";
			}
				std::cout << up << std::endl;
				std::cout <<  "[" << ia << ", " << ib << "]" << std::endl;
			}else{
				std::cout << "--" << std::endl;
			}
		}
		if (command=="cartesian_integers"){
			double c;
			double d;
			std::cin >> c >> d;
			if(d<c){
				std::cout << "--" << std::endl;}
			else if(ia==1&&ib==0){
				std::cout << "--" << std::endl;}
			else{	int low=std::ceil(ia);
					int up=std::floor(ib);
					int low1=std::ceil(c);
					int up1=std::floor(d);
					if(low<=up){
					for(int i=low;i<up;i++){
					for(int j=low1;j<=up1;j++){
						std::cout << "(" << i << ", " << j << ")" << ", ";
					}
					}
					for(int j=low1;j<up1;j++){
						std::cout << "("<< up << ", " << j << ")" << ", ";
					}
					std::cout<< "(" << up << ", " << up1 << ")"<<std::endl;
					std::cout <<  "[" << ia << ", " << ib << "]" << std::endl;
				}
			}	
		}
	}while (command != "exit");
	std::cout << "Bye bye: Terminating interval calculator program." << std::endl;
}

