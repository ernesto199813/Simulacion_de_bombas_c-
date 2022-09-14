#include<iostream>//MOSTRAR DATOS EN PANTALLA/////////////////////////////////////////
#include<fstream>//LEER Y ESCRIBIR EN UN ARCHIVO DE TEXTO////////////////////////
#include<windows.h>//CONTROL DE EJECUCION Y TIEMPO DE REFRESCAMIENTO EN PANTALLA/////////////
using namespace std;
 

int main(){


/////////////TIEMPOB1=TIEMPO EN BOMBA  1 ,TIEMPOB2=TIEMPO EN BOMBA  2 , TIEMPOB3=TIEMPO EN BOMBA  3//////////////////
double tiempoB1=0,tiempoB2=0,tiempoB3=0;
	
string bomba1="APAGADA",bomba2="APAGADA",bomba3="APAGADA";
////////////// TP201=TRANSMISION DE PRESION EN LA VALVULA 201 ,TP202=TRANSMISION DE PRESION EN LA VALVULA 202, TP203=TRANSMISION DE PRESION EN LA VALVULA 203////////// 
double TP201=0,TP202=0,TP203=0;
/////SWITCH DE FLUJO 201 ,SWITCH DE FLUJO 202, SWITCH DE FLUJO 203//////////////////////////////	
string SF201="OFF",SF202="OFF",SF203="OFF";
/////////////////GALONES EN LA BOMBA 1, GALONES EN LA BOMBA 2 , GALONES EN LA BOMBA 3////////////////////////////////
double galones1=0,galones2=0,galones3=0;

double flujototal;

double  aux ; 
////////////////////// GM1=GALONES/SEG EN LA BOMBA 1 , GM2=GALONES/SEG EN LA BOMBA 2 ,GM3=GALONES/SEG EN LA BOMBA 3///////////////////////
double GM1=0,GM2=0 , GM3=0;

	 
string pantalla="ON";

///////////////////////////////////////////////////////////////////////////////////////////////////	 
inicio:
	
ifstream ernesto ("D:\\exam.txt");


string V101;

string V102;

string V103;

string V201;

string V202;

string V203;
	
ernesto>>V101>>V102>>V103>>V201>>V202>>V203;	

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////			




if(pantalla=="ON"){
	
system("cls");


cout<<"\n------------------------LINEA[1]------------------------------------------"<<tiempoB1<<"s"<<endl;
cout<<"bomba(1)="<<bomba1<<endl;	
cout<<"valvula de entrada (101)="<<V101<<endl;
cout<<"switch de flujo (201)="<<SF201<<endl;
cout<<"transmisor de presion(203)="<<TP203<<endl;
cout<<"la valvula de descarga (203)="<<V203<<endl;
cout<<"la cantidad de [galones/min]="<<galones1<<endl;
cout<<"La cantidad de [galones/seg]="<< GM1<<endl;

cout<<"\n------------------------LINEA[2]------------------------------------------"<<tiempoB2<<"s"<<endl;

cout<<"bomba(2)="<<bomba2<<endl;	
cout<<"valvula de entrada (102)="<<V102<<endl;
cout<<"switch de flujo (202)="<<SF202<<endl;
cout<<"transmisor de presion(202)="<<TP202<<endl;
cout<<"la valvula de descarga (202)="<<V202<<endl;
cout<<"la cantidad de [galones/min]="<<galones2<<endl;
cout<<"La cantidad de [galones/seg]="<<GM2 <<endl;


cout<<"\n------------------------LINEA[3]------------------------------------------"<<tiempoB3<<"s"<<endl;	
cout<<"bomba(3)="<<bomba3<<endl;			
cout<<"valvula de entrada (103)="<<V103<<endl;	
cout<<"switch de flujo (203)="<<SF203<<endl;	
cout<<"transmisor de presion(201)="<<TP201<<endl;
cout<<"la valvula de descarga (201)="<<V201<<endl;
cout<<"la cantidad de [galones/min]="<<galones3<<endl;
cout<<"La cantidad de [galones/seg]="<<GM3 <<endl;



cout<<"\nLa cantidad de flujo total que pasa [galones/min]="<<flujototal<<endl;

pantalla="OFF";		
}	
	
Sleep (150);	

////////////////////simulamos el encendido y apagado de los switch de flujos/////////////

if(V101=="ABIERTO" and SF201=="OFF"){
		
SF201="ON";
pantalla="ON";		
}


if(V102=="ABIERTO" and SF202=="OFF"){
	
SF202="ON";
pantalla="ON";		
}


if(V103=="ABIERTO" and SF203=="OFF"){
		
SF203="ON";
pantalla="ON";			
}

if(V101=="ABIERTO" and V102=="CERRADO" and V103=="ABIERTO" and V203=="CERRADO" and V202=="ABIERTO" and  V201=="ABIERTO"||
 V101=="ABIERTO" and V102=="CERRADO" and V103=="ABIERTO" and V203=="CERRADO" and V202=="CERRADO" and  V201=="ABIERTO"){
 	
 if(tiempoB1==tiempoB3){
 if(bomba1=="APAGADA" and SF201=="ON" and TP203<20 ){
	
bomba1="ENCENDIDA";

pantalla="ON";
} }	
 	
 if(TP203>=50){
 if(bomba3=="APAGADA" and SF203=="ON" and TP201<20){
	
bomba3="ENCENDIDA";

pantalla="ON";
} }	
 	
 if(tiempoB1==7 and V203=="CERRADO"){
	
tiempoB1=0;

pantalla="ON";	  	
}
 
 		
 }

if(V101=="CERRADO" and V102=="ABIERTO" and V103=="ABIERTO" and V203=="ABIERTO" and V202=="ABIERTO" and  V201=="CERRADO"||
 V101=="CERRADO" and V102=="ABIERTO" and V103=="ABIERTO" and V203=="CERRADO" and V202=="ABIERTO" and  V201=="CERRADO") {
 	
 if(tiempoB2==tiempoB3|| TP201>=50){
 if(bomba2=="APAGADA" and SF202=="ON" and TP202<20 ){
	
bomba2="ENCENDIDA";

pantalla="ON";
} }


if(tiempoB2>=25){

if(bomba3=="APAGADA" and SF203=="ON" and TP201<20){
	
bomba3="ENCENDIDA";

pantalla="ON";
}}

if(tiempoB3==7 and V201=="CERRADO"){
	
tiempoB3=0;

pantalla="ON";	   	
}

	
 	
 }


if(V101=="CERRADO" and V102=="ABIERTO" and V103=="ABIERTO" and V203=="ABIERTO" and V202=="CERRADO" and  V201=="CERRADO"||
 V101=="CERRADO" and V102=="ABIERTO" and V103=="ABIERTO" and V203=="CERRADO" and V202=="CERRADO" and  V201=="CERRADO"){
 	
 if(bomba2=="APAGADA" and SF202=="ON" and TP202<20 ){
	
bomba2="ENCENDIDA";
pantalla="ON";
} 

if(TP202>=50){
if(bomba3=="APAGADA" and SF203=="ON" and TP201<20){
	
bomba3="ENCENDIDA";
pantalla="ON";
} }	
 	
if(tiempoB2==7 and V202=="CERRADO"){
	
tiempoB2=0;

pantalla="ON";	   	
}

if(tiempoB3==7 and V201=="CERRADO"){
	
tiempoB3=0;

pantalla="ON";	   	
} 	
 	
 	
 }






if(V101=="CERRADO" and V102=="ABIERTO" and V103=="ABIERTO" and V203=="ABIERTO" and V202=="CERRADO" and  V201=="ABIERTO"||
 V101=="CERRADO" and V102=="ABIERTO" and V103=="ABIERTO" and V203=="CERRADO" and V202=="CERRADO" and  V201=="ABIERTO") {
 	
 if(tiempoB2==tiempoB3){
 if(bomba2=="APAGADA" and SF202=="ON" and TP202<20 ){
	
bomba2="ENCENDIDA";

pantalla="ON";
} }


if(TP202>=50){

if(bomba3=="APAGADA" and SF203=="ON" and TP201<20){
	
bomba3="ENCENDIDA";

pantalla="ON";
}}

if(tiempoB2==7 and V202=="CERRADO"){
	
tiempoB2=0;

pantalla="ON";	   	
}

	
 	
 }


if(V101=="ABIERTO" and V102=="CERRADO" and V103=="ABIERTO" and V203=="CERRADO" and V202=="ABIERTO" and  V201=="CERRADO"||
 V101=="ABIERTO" and V102=="CERRADO" and V103=="ABIERTO" and V203=="CERRADO" and V202=="CERRADO" and  V201=="CERRADO"){
 	
 if(bomba1=="APAGADA" and SF201=="ON" and TP203<20 ){
	
bomba1="ENCENDIDA";

pantalla="ON";
} 	
 
 	
 if(TP203>=50){
 if(bomba3=="APAGADA" and SF203=="ON" and TP201<20){
	
bomba3="ENCENDIDA";

pantalla="ON";
}	}
 
 if(tiempoB1==7 and V203=="CERRADO"){
	
tiempoB1=0;

pantalla="ON";	  	
}



if(tiempoB3==7 and V201=="CERRADO"){
	
tiempoB3=0;

pantalla="ON";	   	
}
 	
 	
 }



if(V101=="ABIERTO" and V102=="CERRADO" and V103=="ABIERTO" and V203=="ABIERTO" and V202=="ABIERTO" and  V201=="ABIERTO"||
 V101=="ABIERTO" and V102=="CERRADO" and V103=="ABIERTO" and V203=="ABIERTO" and V202=="CERRADO" and  V201=="ABIERTO"){
 	
if(bomba2=="APAGADA" and bomba3=="APAGADA"){
 if(bomba1=="APAGADA" and SF201=="ON" and TP203<20){
	
bomba1="ENCENDIDA";
pantalla="ON";
}}
		
if(bomba2=="APAGADA" and bomba1=="APAGADA"){
if(bomba3=="APAGADA" and SF201=="ON" and TP201<20){
	
bomba3="ENCENDIDA";
pantalla="ON";
}
}	
 	
 if(bomba1=="ENCENDIDA" and SF201=="ON" and TP203>50){
	
bomba1="APAGADA";

pantalla="ON";
} }



if(V101=="ABIERTO" and V102=="ABIERTO" and V103=="ABIERTO" and V203=="CERRADO" and V202=="ABIERTO" and  V201=="CERRADO"){
	
/////////////////////////////////////////////////////ENCENDIDO DE LA BOMBA1///////////////////////////////////////////////////////////////
if( tiempoB1==tiempoB2 and tiempoB1==tiempoB3 ){
if(bomba1=="APAGADA" and SF201=="ON" and TP203<20 ){
	
bomba1="ENCENDIDA";

pantalla="ON";
} }
/////////////////////////////////////////////////////ENCENDIDO DE LA BOMBA2///////////////////////////////////////////////////////////////
if(TP203>=50 and tiempoB3<5|| TP201>=50 ){

if(bomba2=="APAGADA" and SF202=="ON" and TP202<20 ){
	
bomba2="ENCENDIDA";

pantalla="ON";
} }

/////////////////////////////////////////////////////ENCENDIDO DE LA BOMBA3///////////////////////////////////////////////////////////////
if(tiempoB2>=25  ){
 if(bomba3=="APAGADA" and SF203=="ON" and TP201<20){
	
bomba3="ENCENDIDA";

pantalla="ON";
} }

if(tiempoB1==7 and V203=="CERRADO"){
	
tiempoB1=0;

pantalla="ON";	
   	
}


if(tiempoB3==7 and V201=="CERRADO"){
	
tiempoB3=0;



pantalla="ON";	
   	
}





}


if(V101=="ABIERTO" and V102=="CERRADO" and V103=="ABIERTO" and V203=="ABIERTO" and V202=="ABIERTO" and  V201=="CERRADO" || 

V101=="ABIERTO" and V102=="CERRADO" and V103=="ABIERTO" and V203=="ABIERTO" and V202=="CERRADO" and  V201=="CERRADO"  ){
	
if( tiempoB3==tiempoB1||TP201>=50 ){
if(bomba1=="APAGADA" and SF201=="ON" and TP203<20 ){
	
bomba1="ENCENDIDA";

pantalla="ON";
} }	
	
if(tiempoB1>=25){
if(bomba3=="APAGADA" and SF203=="ON" and TP201<20){
	
bomba3="ENCENDIDA";

pantalla="ON";
}}	
	
if(tiempoB3==7 and V201=="CERRADO"){
	
tiempoB3=0;

pantalla="ON";	
	
}}



if(V101=="ABIERTO" and V102=="ABIERTO" and V103=="CERRADO" and V203=="CERRADO" and V202=="CERRADO" and  V201=="ABIERTO" || 

V101=="ABIERTO" and V102=="ABIERTO" and V103=="CERRADO" and V203=="CERRADO" and V202=="CERRADO" and  V201=="CERRADO"  ){
	

if(bomba1=="APAGADA" and SF201=="ON" and TP203<20 ){
	
bomba1="ENCENDIDA";

pantalla="ON";
}
	
if(TP203>=50)if(bomba2=="APAGADA" and SF202=="ON" and TP202<20 ){
	
bomba2="ENCENDIDA";

pantalla="ON";
} 	
	
if(tiempoB2==7 and V202=="CERRADO"){
	
tiempoB2=0;
pantalla="ON";	   	
}

if(tiempoB1==7 and V203=="CERRADO"){
	
tiempoB1=0;

pantalla="ON";	  	
}	
	
	
	
}


if(V101=="ABIERTO" and V102=="ABIERTO" and V103=="CERRADO" and V203=="CERRADO" and V202=="ABIERTO" and  V201=="ABIERTO"||
V101=="ABIERTO" and V102=="ABIERTO" and V103=="CERRADO" and V203=="CERRADO" and V202=="ABIERTO" and  V201=="CERRADO" ){
	



if(tiempoB1==tiempoB2){
if(bomba1=="APAGADA" and SF201=="ON" and TP203<20 ){
	
bomba1="ENCENDIDA";

pantalla="ON";
} }	
	

if(TP203>=50)
if(bomba2=="APAGADA" and SF202=="ON" and TP202<20 ){
	
bomba2="ENCENDIDA";

pantalla="ON";
} 	
	
if(tiempoB1==7 and V203=="CERRADO"){
	
tiempoB1=0;

pantalla="ON";	  	
}
	
	
	
	
	
	
	
}



if(V101=="ABIERTO" and V102=="ABIERTO" and V103=="CERRADO" and V203=="ABIERTO" and V202=="CERRADO" and  V201=="ABIERTO"||

 V101=="ABIERTO" and V102=="ABIERTO" and V103=="CERRADO" and V203=="ABIERTO" and V202=="CERRADO" and  V201=="CERRADO" ){
	
if( tiempoB1==tiempoB2|| TP202>=50 ){
if(bomba1=="APAGADA" and SF201=="ON" and TP203<20 ){
	
bomba1="ENCENDIDA";

pantalla="ON";
} }
/////////////////////////////////////////////////////ENCENDIDO DE LA BOMBA2///////////////////////////////////////////////////////////////

if(tiempoB1>=25)
if(bomba2=="APAGADA" and SF202=="ON" and TP202<20 ){
	
bomba2="ENCENDIDA";

pantalla="ON";
} 	
	
if(tiempoB2==7 and V202=="CERRADO"){
	
tiempoB2=0;
pantalla="ON";	   	
}	
	
	
	
	
	
	
}

if(V101=="ABIERTO" and V102=="ABIERTO" and V103=="ABIERTO" and V203=="ABIERTO" and V202=="CERRADO" and  V201=="CERRADO"){

/////////////////////////////////////////////////////ENCENDIDO DE LA BOMBA1///////////////////////////////////////////////////////////////
if( tiempoB1==tiempoB2 and tiempoB1==tiempoB3 || TP202>=50 and TP201>=50){
if(bomba1=="APAGADA" and SF201=="ON" and TP203<20 ){
	
bomba1="ENCENDIDA";

pantalla="ON";
} }
/////////////////////////////////////////////////////ENCENDIDO DE LA BOMBA2///////////////////////////////////////////////////////////////
if(tiempoB1>=25 ){

if(bomba2=="APAGADA" and SF202=="ON" and TP202<20 ){
	
bomba2="ENCENDIDA";

pantalla="ON";
} }

/////////////////////////////////////////////////////ENCENDIDO DE LA BOMBA3///////////////////////////////////////////////////////////////
if(TP202>=50  ){
 if(bomba3=="APAGADA" and SF203=="ON" and TP201<20){
	
bomba3="ENCENDIDA";

pantalla="ON";
} }  

if(tiempoB2==7 and V202=="CERRADO"){
	
tiempoB2=0;

pantalla="ON";	   	
}

if(tiempoB3==7 and V201=="CERRADO"){
	
tiempoB3=0;

pantalla="ON";	
   	
}



}


if(V101=="ABIERTO" and V102=="ABIERTO" and V103=="ABIERTO" and V203=="CERRADO" and V202=="CERRADO" and  V201=="ABIERTO"){
	
	
/////////////////////////////////////////////////////ENCENDIDO DE LA BOMBA1///////////////////////////////////////////////////////////////
if( tiempoB1==tiempoB2 and tiempoB1==tiempoB3){
if(bomba1=="APAGADA" and SF201=="ON" and TP203<20 ){
	
bomba1="ENCENDIDA";

pantalla="ON";
} }
/////////////////////////////////////////////////////ENCENDIDO DE LA BOMBA2///////////////////////////////////////////////////////////////
if(TP203>=50 ){

if(bomba2=="APAGADA" and SF202=="ON" and TP202<20 ){
	
bomba2="ENCENDIDA";

pantalla="ON";
} }

/////////////////////////////////////////////////////ENCENDIDO DE LA BOMBA3///////////////////////////////////////////////////////////////
if(TP202>=50 and TP203>=50 ){
 if(bomba3=="APAGADA" and SF203=="ON" and TP201<20){
	
bomba3="ENCENDIDA";

pantalla="ON";
} }               

if(tiempoB2==7 and V202=="CERRADO"){
	
tiempoB2=0;

pantalla="ON";	
   	
}



if(tiempoB1==7 and V203=="CERRADO"){
	
tiempoB1=0;

pantalla="ON";	  	
}





}

if(V101=="ABIERTO" and V102=="ABIERTO" and V103=="CERRADO" and V203=="ABIERTO" and V202=="ABIERTO" and  V201=="ABIERTO"||
 V101=="ABIERTO" and V102=="ABIERTO" and V103=="CERRADO" and V203=="ABIERTO" and V202=="ABIERTO" and  V201=="CERRADO"){

///////////////////////////////////ENCENDIDO DE LA BOMBA 1 /////////////////////////////////////////////////////////////////
	
if(bomba2=="APAGADA" and bomba3=="APAGADA"){
if(bomba1=="APAGADA" and SF201=="ON" and TP203<20){
	
bomba1="ENCENDIDA";

pantalla="ON";
}}
///////////////////////////////////ENCENDIDO DE LA BOMBA 2 /////////////////////////////////////////////////////////////////
if(bomba1=="APAGADA" and bomba3=="APAGADA"){
if(bomba2=="APAGADA" and SF201=="ON" and TP202<20){
	
bomba2="ENCENDIDA";

pantalla="ON";
}}}

if(V101=="ABIERTO" and V102=="ABIERTO" and V103=="ABIERTO" and V203=="CERRADO" and V202=="CERRADO" and  V201=="CERRADO"){
	
if(bomba1=="APAGADA" and SF201=="ON" and TP203<20 ){
	
bomba1="ENCENDIDA";

pantalla="ON";
} 


if(tiempoB1==7){
if(bomba2=="APAGADA" and SF202=="ON" and TP202<20 ){
	
bomba2="ENCENDIDA";

pantalla="ON";
} }

if(tiempoB2==7){
	
if(bomba3=="APAGADA" and SF203=="ON" and TP201<20){
	
bomba3="ENCENDIDA";

pantalla="ON";
} }
	
if(tiempoB2==7 and V202=="CERRADO"){
	
tiempoB2=0;

pantalla="ON";	
   	
}


if(tiempoB1==7 and V203=="CERRADO"){
	
tiempoB1=0;

pantalla="ON";	  	
}

if(tiempoB3==7 and V201=="CERRADO"){
	
tiempoB3=0;

pantalla="ON";	
   	
}	
	
	
pantalla="ON";	
} 



if(V101=="ABIERTO" and V102=="ABIERTO" and V103=="ABIERTO" and V203=="ABIERTO" and V202=="ABIERTO" and  V201=="ABIERTO"){
	
///////////////////hacemos el apagado y el encendido de las bombas/////////

/////////////////////////////////////////////////////ENCENDIDO DE LA BOMBA1///////////////////////////////////////////////////////////////
if( bomba3=="APAGADA" and tiempoB3>=25||tiempoB1==tiempoB2 and tiempoB1==tiempoB3){
if(bomba1=="APAGADA" and SF201=="ON" and TP203<20 ){
	
bomba1="ENCENDIDA";

pantalla="ON";
} }
/////////////////////////////////////////////////////ENCENDIDO DE LA BOMBA2///////////////////////////////////////////////////////////////
if(bomba1=="APAGADA" and tiempoB1>=25 and tiempoB3<25 ){

if(bomba2=="APAGADA" and SF202=="ON" and TP202<20 ){
	
bomba2="ENCENDIDA";

pantalla="ON";
} }

/////////////////////////////////////////////////////ENCENDIDO DE LA BOMBA3///////////////////////////////////////////////////////////////
if(bomba2=="APAGADA" and tiempoB1<25 and tiempoB2>=25  ){
 if(bomba3=="APAGADA" and SF203=="ON" and TP201<20){
	
bomba3="ENCENDIDA";

pantalla="ON";
} } }

if( V101=="ABIERTO" and V102=="CERRADO" and V103=="ABIERTO" and V203=="ABIERTO" and V202=="ABIERTO" and  V201=="ABIERTO"||  
V101=="ABIERTO" and V102=="CERRADO" and V103=="ABIERTO" and V203=="ABIERTO" and V202=="CERRADO" and  V201=="ABIERTO" ){
	
////////////////////////HACEMOS EL ENCENDIDO DE LAS BOMBAS///////////////////////////////////////////////////////////

//////////////////////////////////ENCENDIDO DE LA BOMBA 1///////////////////////////////////////////////	
if(bomba3=="APAGADA" and bomba2=="APAGADA"){
if(bomba1=="APAGADA" and SF201=="ON" and TP203<20 ){
	
bomba1="ENCENDIDA";

pantalla="ON";
} }	
//////////////////////////////////ENCENDIDO DE LA BOMBA 3///////////////////////////////////////////////	
if(bomba2=="APAGADA" and bomba1=="APAGADA" ){
 if(bomba3=="APAGADA" and SF203=="ON" and TP201<20){
	
bomba3="ENCENDIDA";

pantalla="ON";
} }	}

if( V101=="CERRADO" and V102=="ABIERTO" and V103=="ABIERTO" and V203=="ABIERTO" and V202=="ABIERTO" and  V201=="ABIERTO"||  
V101=="CERRADO" and V102=="ABIERTO" and V103=="ABIERTO" and V203=="CERRADO" and V202=="ABIERTO" and  V201=="ABIERTO" ){

////////////////////////HACEMOS EL APAGADO Y ENCENDIDO DE LAS BOMBAS/////////////////////////////////////////////////////////////

//////////////////////////////////ENCENDIDO DE LA BOMBA 2///////////////////////////////////////////////	
if(bomba1=="APAGADA" and bomba3=="APAGADA"){

if(bomba2=="APAGADA" and SF202=="ON" and TP202<20 ){
	
bomba2="ENCENDIDA";

pantalla="ON";
} }

//////////////////////////////////ENCENDIDO DE LA BOMBA 3///////////////////////////////////////////////
if(bomba2=="APAGADA" and bomba1=="APAGADA" ){
 if(bomba3=="APAGADA" and SF203=="ON" and TP201<20){
	
bomba3="ENCENDIDA";

pantalla="ON";
} }	}


if(V101=="ABIERTO" and V102=="ABIERTO" and V103=="ABIERTO" and V203=="ABIERTO" and V202=="CERRADO" and  V201=="ABIERTO"){


if( bomba3=="APAGADA" and tiempoB3>=25||tiempoB1==tiempoB2 and tiempoB1==tiempoB3||TP202>=50 and tiempoB3>=25){
if(bomba1=="APAGADA" and SF201=="ON" and TP203<20 ){
	
bomba1="ENCENDIDA";

pantalla="ON";
} }
/////////////////////////////////////////////////////ENCENDIDO DE LA BOMBA2///////////////////////////////////////////////////////////////
if(bomba1=="APAGADA" and tiempoB1>=25 and tiempoB3<25 ){

if(bomba2=="APAGADA" and SF202=="ON" and TP202<20 ){
	
bomba2="ENCENDIDA";

pantalla="ON";
} }

/////////////////////////////////////////////////////ENCENDIDO DE LA BOMBA3///////////////////////////////////////////////////////////////
if(bomba1=="APAGADA"  and TP202>=50  ){
 if(bomba3=="APAGADA" and SF203=="ON" and TP201<20){
	
bomba3="ENCENDIDA";

pantalla="ON";
} } 

if(tiempoB2==7 and V202=="CERRADO"){
	
tiempoB2=0;



pantalla="ON";	
   	
}





}



if(V101=="ABIERTO" and V102=="ABIERTO" and V103=="ABIERTO" and V203=="CERRADO" and V202=="ABIERTO" and  V201=="ABIERTO"){

if( bomba3=="APAGADA" and tiempoB3>=25||tiempoB1==tiempoB2 and tiempoB1==tiempoB3||TP202>=50 and tiempoB3>=25){
if(bomba1=="APAGADA" and SF201=="ON" and TP203<20 ){
	
bomba1="ENCENDIDA";

pantalla="ON";
} }
/////////////////////////////////////////////////////ENCENDIDO DE LA BOMBA2///////////////////////////////////////////////////////////////
if(bomba1=="APAGADA" and bomba3=="APAGADA" and TP203>=50 ){

if(bomba2=="APAGADA" and SF202=="ON" and TP202<20 ){
	
bomba2="ENCENDIDA";

pantalla="ON";
} }

/////////////////////////////////////////////////////ENCENDIDO DE LA BOMBA3///////////////////////////////////////////////////////////////
if(bomba1=="APAGADA"  and tiempoB2>=25 ){
 if(bomba3=="APAGADA" and SF203=="ON" and TP201<20){
	
bomba3="ENCENDIDA";

pantalla="ON";
} }

if(tiempoB1==7 and V203=="CERRADO"){
	
tiempoB1=0;



pantalla="ON";	
   	
}






}


if(V101=="ABIERTO" and V102=="ABIERTO" and V103=="ABIERTO" and V203=="ABIERTO" and V202=="ABIERTO" and  V201=="CERRADO"){


if( tiempoB1==tiempoB2 and tiempoB1==tiempoB3||TP201>=50 and bomba2=="APAGADA"){
if(bomba1=="APAGADA" and SF201=="ON" and TP203<20 ){
	
bomba1="ENCENDIDA";

pantalla="ON";
} }
/////////////////////////////////////////////////////ENCENDIDO DE LA BOMBA2///////////////////////////////////////////////////////////////
if(bomba1=="APAGADA" and tiempoB1>=25 ){

if(bomba2=="APAGADA" and SF202=="ON" and TP202<20 ){
	
bomba2="ENCENDIDA";

pantalla="ON";
} }

/////////////////////////////////////////////////////ENCENDIDO DE LA BOMBA3///////////////////////////////////////////////////////////////
if(bomba1=="APAGADA"  and tiempoB2>=25 ){
 if(bomba3=="APAGADA" and SF203=="ON" and TP201<20){
	
bomba3="ENCENDIDA";

pantalla="ON";
} }

if(tiempoB3==7 and V201=="CERRADO"){
	
tiempoB3=0;



pantalla="ON";	
   	
}




}


if(V101=="ABIERTO" and V102=="CERRADO" and V103=="CERRADO" and V203=="ABIERTO" and V202=="ABIERTO" and  V201=="ABIERTO"||

 V101=="ABIERTO" and V102=="CERRADO" and V103=="CERRADO" and V203=="ABIERTO" and V202=="CERRADO" and  V201=="CERRADO" ||
 
 V101=="ABIERTO" and V102=="CERRADO" and V103=="CERRADO" and V203=="ABIERTO" and V202=="CERRADO" and  V201=="ABIERTO"||
 
 V101=="ABIERTO" and V102=="CERRADO" and V103=="CERRADO" and V203=="ABIERTO" and V202=="ABIERTO" and  V201=="CERRADO"
 
  ){///////////////////hacemos el apagado y el encendido de las bombas/////////


if(bomba1=="APAGADA" and SF201=="ON" and TP203<20){
	
bomba1="ENCENDIDA";

pantalla="ON";
}}



if(V101=="CERRADO" and V102=="ABIERTO" and V103=="CERRADO" and V203=="ABIERTO" and V202=="ABIERTO" and  V201=="ABIERTO"||

 V101=="CERRADO" and V102=="ABIERTO" and V103=="CERRADO" and V203=="CERRADO" and V202=="ABIERTO" and  V201=="CERRADO" ||
 
 V101=="CERRADO" and V102=="ABIERTO" and V103=="CERRADO" and V203=="ABIERTO" and V202=="ABIERTO" and  V201=="CERRADO"||
 
 V101=="CERRADO" and V102=="ABIERTO" and V103=="CERRADO" and V203=="CERRADO" and V202=="ABIERTO" and  V201=="ABIERTO"
 
  ){ ///////////////////hacemos el apagado y el encendido de las bombas/////////


if(bomba2=="APAGADA" and SF202=="ON" and TP202<20 ){
	
bomba2="ENCENDIDA";

pantalla="ON";
} 

}


if(V101=="CERRADO" and V102=="CERRADO" and V103=="ABIERTO" and V203=="ABIERTO" and V202=="ABIERTO" and  V201=="ABIERTO"||

 V101=="CERRADO" and V102=="CERRADO" and V103=="ABIERTO" and V203=="CERRADO" and V202=="CERRADO" and  V201=="ABIERTO" ||
 
 V101=="CERRADO" and V102=="CERRADO" and V103=="ABIERTO" and V203=="ABIERTO" and V202=="CERRADO" and  V201=="ABIERTO"||
 
 V101=="CERRADO" and V102=="CERRADO" and V103=="ABIERTO" and V203=="CERRADO" and V202=="ABIERTO" and  V201=="ABIERTO"
 
  ){///////////////////hacemos el apagado y el encendido de las bombas/////////


if(bomba3=="APAGADA" and SF203=="ON" and TP201<20){
	
bomba3="ENCENDIDA";

pantalla="ON";
}}

if(V101=="CERRADO" and V102=="CERRADO" and V103=="CERRADO" and V203=="CERRADO" and V202=="CERRADO" and  V201=="CERRADO"||

V101=="CERRADO" and V102=="CERRADO" and V103=="CERRADO" and V203=="ABIERTO" and V202=="ABIERTO" and  V201=="ABIERTO"||

V101=="CERRADO" and V102=="CERRADO" and V103=="CERRADO" and V203=="ABIERTO" and V202=="CERRADO" and  V201=="CERRADO"||
V101=="CERRADO" and V102=="CERRADO" and V103=="CERRADO" and V203=="CERRADO" and V202=="ABIERTO" and  V201=="CERRADO"||

V101=="CERRADO" and V102=="CERRADO" and V103=="CERRADO" and V203=="CERRADO" and V202=="CERRADO" and  V201=="ABIERTO"){

flujototal=0;

pantalla="ON";

	
}	


if(TP203>=50 and V203=="ABIERTO"){
	
	
	
	TP203=0;
	
	pantalla="ON";
}

if(TP202>=50 and V202=="ABIERTO"){
	
	
	
	TP202=0;
	
	pantalla="ON";
}


if(TP201>=50 and V201=="ABIERTO"){
	
	
	
	TP201=0;
	
	pantalla="ON";
}












///////////////////////////////////////////////APAGADO DE LAS BOMBAS ///////////////////////////////////////////////

/////////////////////////////////////////////////////APAGADO DE LA BOMBA 1////////////////////////////////////////////
if(bomba1=="ENCENDIDA" and SF201=="ON" and TP203>50){
	
bomba1="APAGADA";

pantalla="ON";
}
/////////////////////////////////////////////////////APAGADO DE LA BOMBA 2////////////////////////////////////////////
if(bomba2=="ENCENDIDA" and SF202=="ON" and TP202>50){
	
bomba2="APAGADA";

pantalla="ON";
}
/////////////////////////////////////////////////////APAGADO DE LA BOMBA 3////////////////////////////////////////////
if(bomba3=="ENCENDIDA" and SF203=="ON" and TP201>50){
	
bomba3="APAGADA";

pantalla="ON";
}
/////////////////////////////////////////////////////APAGADO DE LA BOMBA 1////////////////////////////////////////////

if(bomba1=="ENCENDIDA" and SF201=="OFF"){
	
bomba1="APAGADA";

pantalla="ON";
}
/////////////////////////////////////////////////////APAGADO DE LA BOMBA 2////////////////////////////////////////////
if(bomba2=="ENCENDIDA" and SF202=="OFF" ){
	
bomba2="APAGADA";

pantalla="ON";
}
/////////////////////////////////////////////////////APAGADO DE LA BOMBA 3////////////////////////////////////////////
if(bomba3=="ENCENDIDA" and SF203=="OFF" ){
	
bomba3="APAGADA";

pantalla="ON";
}

	
	


//simulamos la presion al arrancar al apagar la bomba 


/////////////SIMULAMOS LA PRESION DE LA BOMBA 1/////////////////////////////////////////////////////////////////////////////

if(bomba1=="ENCENDIDA" and V203=="ABIERTO" and TP203<33 and tiempoB1<25 ){
	
TP203=TP203+4.125;

pantalla="ON";	}
	
	
if(bomba1=="ENCENDIDA" and V203=="CERRADO" and TP203<50 ){
	
TP203=TP203+6.25;

pantalla="ON";	}
	
if(TP203>=50 and bomba1=="ENCENDIDA"){
	
bomba1="APAGADA";

pantalla="ON";			
}


if( V203=="ABIERTO" and tiempoB1>25 and tiempoB1<=33 and TP203>0 ){
	

TP203=TP203-4.25;	
			
pantalla="ON";	
}

/////////////////////////////////////////SIMULAMOS LA PRESION DE LA BOMBA 2////////////////////////////////////////////////////////////////

if(bomba2=="ENCENDIDA" and V202=="ABIERTO" and TP202<33 and tiempoB2<25 ){
	
TP202=TP202+4.125;

pantalla="ON";	}
	
	
if(bomba2=="ENCENDIDA" and V202=="CERRADO" and TP202<50 ){
	
TP202=TP202+6.25;

pantalla="ON";	}
	
if(TP202>=50 and bomba2=="ENCENDIDA"){
	
bomba2="APAGADA";

pantalla="ON";			
}


if( V202=="ABIERTO" and tiempoB2>25 and tiempoB2<=33 and TP202>0 ){
	

TP202=TP202-4.25;	
			
pantalla="ON";	
}


////////////////////////////////////////////SIMULAMOS LA PRESION DE LA BOMBA 3 ////////////////////////////////////////////////////////////
if(bomba3=="ENCENDIDA" and V201=="ABIERTO" and TP201<33 and tiempoB3<25 ){
	
TP201=TP201+4.125;

pantalla="ON";	}
	
	
if(bomba3=="ENCENDIDA" and V201=="CERRADO" and TP201<50 ){
	
TP201=TP201+6.25;

pantalla="ON";	}
	
if(TP201>=50 and bomba3=="ENCENDIDA"){
	
bomba3="APAGADA";

pantalla="ON";			
}


if( V201=="ABIERTO" and tiempoB3>25 and tiempoB3<=33 and TP201>0 ){
	

TP201=TP201-4.25;	
			
pantalla="ON";	
}	
////////////////simulamos el tiempo de conteo///////////////////////////////////////////////////////

///////////////TIEMPO DE CONTEO DE LA BOMBA 1///////////////////////////////////////////////////////////
if(bomba1=="ENCENDIDA" and tiempoB1<25){
tiempoB1=tiempoB1+1;
pantalla="ON";	
		}

if(bomba1=="ENCENDIDA" and tiempoB1>=25){
bomba1="APAGADA";				
pantalla="ON";
}

if(bomba1=="APAGADA" and tiempoB1>=25 and tiempoB1<=33){	
tiempoB1=tiempoB1+1;	
pantalla="ON";		
}

if(bomba1=="APAGADA" and tiempoB1>33){
	
tiempoB1=0;	
	
pantalla="ON";	
}
//////////////////////////////////////////TIEMPO DE CONTEO DE LA BOMBA 2/////////////////////////////////////////////////////////////
if(bomba2=="ENCENDIDA" and tiempoB2<25){
tiempoB2=tiempoB2+1;
pantalla="ON";	
		}

if(bomba2=="ENCENDIDA" and tiempoB2>=25){	
bomba2="APAGADA";				
pantalla="ON";
}

if(bomba2=="APAGADA" and tiempoB2>=25 and tiempoB2<=33){	
tiempoB2=tiempoB2+1;	
pantalla="ON";		
}



if( bomba2=="APAGADA" and tiempoB2>33){	
tiempoB2=0;		
pantalla="ON";	
}

///////////////////////////////////////////////TIEMPO DE CONTEO DE LA BOMBA 3///////////////////////////////////////
if(bomba3=="ENCENDIDA" and tiempoB3<25){
tiempoB3=tiempoB3+1;
pantalla="ON";	
		}

if(bomba3=="ENCENDIDA" and tiempoB3>=25){
bomba3="APAGADA";				
pantalla="ON";
}

if(bomba3=="APAGADA" and tiempoB3>=25 and tiempoB3<=33){
tiempoB3=tiempoB3+1;	
pantalla="ON";	
	}



if( bomba3=="APAGADA" and tiempoB3>33){	
tiempoB3=0;		
pantalla="ON";	
}

	
/////////////////////////contador de galones cuando el tiempo es de 0 hasta 8 ////////////////////////////////////////////////////////////////////////////////////	

///////////////////////////////////////////////////////////BOMBA 1 CUANDO VA DESDE 0 HASTA 8///////////////////////////////////////////////////	
if(bomba1=="ENCENDIDA" and V203=="ABIERTO" and tiempoB1<=8 ){

galones1=galones1+5;	

aux=galones1/60;

GM1=GM1+aux;

aux=0;

pantalla="ON";	}
///////////////////////////////////////////////////////////BOMBA 2 CUANDO VA DESDE 0 HASTA 8///////////////////////////////////////////////////		
if(bomba2=="ENCENDIDA" and V202=="ABIERTO" and tiempoB2<=8 ){

galones2=galones2+5;	

aux=galones2/60;

GM2=GM2+aux;
aux=0;
pantalla="ON";	}
///////////////////////////////////////////////////////////BOMBA 3 CUANDO VA DESDE 0 HASTA 8///////////////////////////////////////////////////	
if(bomba3=="ENCENDIDA" and V201=="ABIERTO" and tiempoB3<=8 ){

galones3=galones3+5;	

aux=galones3/60;

GM3=GM3+aux;
aux=0;

pantalla="ON";	}

////////////////////////////////////////////////////contador de galones cuando va de 8 hasta 25/////////////////////////////////////


//////////////////////////////////////////////////////BOMBA 1 CUANDO VA DE 8 A 25 ////////////////////////////
if(bomba1=="ENCENDIDA" and V203=="ABIERTO" and tiempoB1>=8 and tiempoB1<25 ){
	
aux=galones1/60;

GM1=GM1+aux;

pantalla="ON";	}
//////////////////////////////////////////////////////BOMBA 2 CUANDO VA DE 8 A 25 ////////////////////////////
if(bomba2=="ENCENDIDA" and V202=="ABIERTO" and tiempoB2>=8 and tiempoB2<25 ){
	
aux=galones2/60;

GM2=GM2+aux;

pantalla="ON";	}

//////////////////////////////////////////////////////BOMBA 3 CUANDO VA DE 8 A 25 ////////////////////////////
if(bomba3=="ENCENDIDA" and V201=="ABIERTO" and tiempoB3>=8 and tiempoB3<25 ){
	
aux=galones3/60;

GM3=GM3+aux;

pantalla="ON";	}

//////////////////////////////////////////////////////contador cuando la bomba va desde 25 hasta 33/////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////BOMBA 1 de 25 a 33 /////////////////////////////////////////////////////
if (bomba1=="APAGADA" and V203=="ABIERTO" and  tiempoB1>=25 and tiempoB1<=33){
	
galones1=galones1-5;

pantalla="ON";}		
	
if(bomba1=="APAGADA" and  GM1<15){
	
GM1=GM1-1.80;		
pantalla="ON";	
}	

///////////////////////////////////////////////////////////BOMBA 2    DE 25 A 33 /////////////////////////////////////////////////////////////////////////////////////////////////

if (bomba2=="APAGADA" and V202=="ABIERTO" and  tiempoB2>=25 and tiempoB2<=33){
	
galones2=galones2-5;

pantalla="ON";}		
	
if(bomba2=="APAGADA" and  GM2<15){
	
GM2=GM2-1.80;		
pantalla="ON";	
}	
//////////////////////////////////////////////////////////////BOMBA 3 DE 25 A 33////////////////////////////////////////////////

if (bomba3=="APAGADA" and V201=="ABIERTO" and  tiempoB3>=25 and tiempoB3<=33){
	
galones3=galones3-5;

pantalla="ON";}		
	
if(bomba3=="APAGADA" and  GM3<15){
	
GM3=GM3-1.80;		
pantalla="ON";	
}


///////evitamos que los [galones/min] den negativo///////////////////////////////

if(galones1<0){
	
galones1=0;
pantalla="ON";		
}

if(galones2<0 ){
	
galones2=0;
pantalla="ON";		
}

if(galones3<0 ){	
galones3=0;
pantalla="ON";		
}

//evitamos que los [galones/seg] den negativo////////////////////////////////
if(GM1<0){
	
GM1=0;
pantalla="ON";		
}

if(GM2<0 ){
	
GM2=0;
pantalla="ON";		
}

if(GM3<0){	
GM3=0;
pantalla="ON";		
}


	
//evitamos que la presion de negativo //////////////////////////////////////////////////////////////////////////////////////////////////////////////

if(TP201<0){
	
TP201=0;

pantalla="ON";
}

if(TP202<0){
	
TP202=0;

pantalla="ON";
}


if(TP203<0){
	
TP203=0;

pantalla="ON";
}
///////////////evitamos que la presion pase de 50 ////
if(TP201>50){
	
TP201=50;

pantalla="ON";
}

if(TP202>50){
	
TP203=50;

pantalla="ON";
}

if(TP203>50){
	
TP203=50;

pantalla="ON";
}


flujototal=galones1+galones2+galones3;	


	
goto inicio;	
}
