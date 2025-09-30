#include<stdio.h>
int main(){
	int thang, nam,ngay;
	printf("nhap thang: "); scanf("%d",&thang);
	printf("nhap nam: "); scanf("%d",&nam);
	if (thang == 1||thang == 3||thang == 5||thang == 7||thang == 8||thang == 10||thang == 12){
		ngay = 31;
	} else if(thang == 4||thang == 6||thang == 9||thang == 11){
		ngay = 30;
	} else if(thang == 2 ){
		if ((nam % 4 == 0 && nam % 100 != 0 )| nam % 400 == 0){
	    ngay = 29;
	}else {
		ngay = 28;
	}
}
	else {
		ngay = 0;
	
}
	if (ngay == 0){
		printf("thang ko hop le");
} else{
	printf("so ngay trong thang %d nam %d la: %d\n", thang,nam,ngay);
}
return 0;
}

