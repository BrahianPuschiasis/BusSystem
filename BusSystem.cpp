#include<stdio.h>
#include<conio.h>
#include<string.h>


struct altas_viajes{
int numero_de_viaje;
int numero_de_omnibus;
int dia, mes, anio;
int hora, min;
char tipo_de_recorrido[30];
char chofer[40];
char guarda[40];
};

struct altas_recorrido{
int numero_de_recorrido;
int numero_de_omnibus;
char origen[40];
char destino[40];
int distancia_en_kilometros, cantidad_de_paradas_intermedias, duracion_en_horas;
};
struct altas_omnibus{
int numero_de_omnibus, asientos;
};

struct altas_pasajes{
int numero_de_pasaje;
int numero_de_omnibus;
int km_hasta_destino, precio_por_kilometro, precio_final, distancia_entre_paradas;
};

void altas();
void consultas();
void administracion();
void informacion();
void bajas();
void ventas();
void listados();


void main (){
clrscr();
int opcion;
do
{
clrscr();
printf("1-Administracion");
printf("\n2-Informacion");
printf("\n3-Ventas");
printf("\n0-Salir");
printf("\nIngrese una opcion:");
scanf("%i",&opcion);
switch (opcion){
case 1: administracion();
break;
case 2: informacion();
break;
case 3: ventas();
break;
}
}
while (opcion != 0);
}

void administracion(){
int opcion;
clrscr();
printf("1-Altas");
printf("\n2-Bajas");
printf("\nIngrese una opcion:");
scanf("%i",&opcion);
switch (opcion){
case 1: altas(); break;
case 2: bajas(); break;
}
}

void informacion()
{
int opcion;
clrscr();
printf("1-Consultas");
printf("\n2-Listados");
printf("\nIngrese una opcion:");
scanf("%i",&opcion);
switch (opcion){
case 1: consultas(); break;
case 2: listados(); break;
}
}

void altas()
{
clrscr();
int op, i, numero_de_omnibus, numero_de_recorrido, numero_de_pasaje, numero_de_viaje;
struct altas_viajes av;
struct altas_recorrido ar;
struct altas_omnibus ao;
struct altas_pasajes ap;
printf("1-Viajes");
printf("\n2-Recorridos");
printf("\n3-Omnibus");
printf("\n4-Pasajes");
scanf("%i",&op);
switch (op) {
case 1:
FILE *viajes;
	viajes=fopen("c:\\altaviaj","ab+");
		if (viajes==NULL){
		printf(" Error al intentar crear/abrir el archivo");
		getch();
		}else
			{
			clrscr();
			av.hora=0;
			av.min=0;
			av.mes=0;
			av.anio=0;
			av.dia=0;
			av.numero_de_omnibus=0;
			av.numero_de_viaje;
			for (i=0;i<=29;i++) av.tipo_de_recorrido[i]=' ';
			for (i=0;i<=39;i++) av.chofer[i]=' ';
			for (i=0;i<=39;i++) av.guarda[i]=' ';

				clrscr();
				printf(" Ingrese numero de viaje(0=Salir):");
				scanf("%i",&numero_de_viaje);
				}
				if(numero_de_viaje>0){

					rewind(viajes);
					while(!feof(viajes)){
					fread(&av,sizeof(struct altas_viajes),1,viajes);
					if(numero_de_viaje==av.numero_de_viaje){

					printf("Ya existe");
					printf("\nVuelva a ingresar un numero de viaje:");
					scanf("%i",&numero_de_viaje);
					rewind(viajes);
					}
					}


				       }if(numero_de_viaje != 0){
					av.numero_de_viaje=numero_de_viaje;
					clrscr();
					printf("Ingrese numero de omnibus: "); scanf("%i",&av.numero_de_omnibus);
					clrscr();
					printf("Ingrese el dia del viaje: ");scanf("%i",&av.dia);
					clrscr();
					printf("Ingrese el mes del viaje: ");scanf("%i",&av.mes);
					clrscr();
					printf("Ingrese el anio del viaje: ");scanf("%i",&av.anio);
					clrscr();
					printf("Ingrese la hora del viaje( solo horas): ");scanf("%i",&av.hora);
					clrscr();
					printf("Ingrese los minutos (solo minutos): ");scanf("%i",&av.min);
					clrscr();
					printf("Ingrese el tipo de recorrido ( Directo o Semidirecto ): \n"); scanf("%s",&av.tipo_de_recorrido); flushall();
					clrscr();
					printf("Ingrese el nombre del chofer del omnibus: "); scanf("%s",&av.chofer);flushall();
					clrscr();
					printf("Ingrese el nombre del guarda del omnibus: "); scanf("%s",&av.guarda); flushall();
					clrscr();
					fwrite(&av,sizeof(struct altas_viajes),1,viajes);
					rewind(viajes);
					fclose(viajes);
					}
						if(numero_de_viaje<0){
						clrscr();
						printf("Error numero de viaje < 0");
						getch();
						}

					break;
case 2:
FILE *recorrido;
	recorrido=fopen("c:\\altareco","ab+");
		if (recorrido==NULL){
		printf(" Error al intentar crear/abrir el archivo");
		getch();
		}else
			{
			clrscr();
			ar.numero_de_recorrido;
			ar.duracion_en_horas=0;
			ar.cantidad_de_paradas_intermedias=0;
			ar.distancia_en_kilometros=0;
			ar.numero_de_omnibus=0;
			for (i=0;i<=29;i++) ar.origen[i]=' ';
			for (i=0;i<=39;i++) ar.destino[i]=' ';

				clrscr();
				printf(" Ingrese numero de recorrido(0=Salir):");
				scanf("%i",&numero_de_recorrido);
				}
				if(numero_de_recorrido>0){

					rewind(recorrido);
					while(!feof(recorrido)){
					fread(&ar,sizeof(struct altas_recorrido),1,recorrido);
					if(numero_de_recorrido==ar.numero_de_recorrido){

					printf("Ya existe");
					printf("\nVuelva a ingresar un numero de recorrido:");
					scanf("%i",&numero_de_recorrido);
					rewind(recorrido);
					}
					}


				       }if(numero_de_omnibus != 0){
					ar.numero_de_recorrido=numero_de_recorrido;
					clrscr();
					printf("Ingrese numero de omnibus: "); scanf("%i",&ar.numero_de_omnibus);
					clrscr();
					printf("Ingrese el origen del viaje: ");scanf("%s",&ar.origen); flushall();
					clrscr();
					printf("Ingrese el destino del viaje: ");scanf("%s",&ar.destino); flushall();
					clrscr();
					printf("Ingrese la distancia del viaje en kilometros (solo numero) ");scanf("%i",&ar.distancia_en_kilometros); flushall();
					clrscr();
					printf("Ingrese la cantidad de paradas intermedias del viaje: ");scanf("%i",&ar.cantidad_de_paradas_intermedias); flushall();
					clrscr();
					printf("Ingrese la duracion en horas del viaje (solo horas): ");scanf("%i",&ar.duracion_en_horas); flushall();
					clrscr();
					fwrite(&ar,sizeof(struct altas_recorrido),1,recorrido);
					rewind(recorrido);
					fclose(recorrido);
					}
						if(numero_de_recorrido<0){
						clrscr();
						printf("Error numero de recorrido < 0");
						getch();
						}

					break;
case 3:
FILE *omnibus;
omnibus=fopen("c:\\altabus","ab+");
		if (omnibus==NULL){
		printf(" Error al intentar crear/abrir el archivo");
		getch();
		}else
			{
			clrscr();
			ao.asientos=0;
			ao.numero_de_omnibus;

				clrscr();
				printf(" Ingrese numero de omnibus(0=Salir):");
				scanf("%i",&numero_de_omnibus);
				}
				if(numero_de_omnibus>0){

					rewind(omnibus);
					while(!feof(omnibus)){
					fread(&ao,sizeof(struct altas_omnibus),1,omnibus);
					if(numero_de_omnibus==ao.numero_de_omnibus){

					printf("Ya existe");
					printf("\nVuelva a ingresar un numero de omnibus:");
					scanf("%i",&numero_de_omnibus);
					rewind(omnibus);
					}
					}


				       }if(numero_de_omnibus != 0){
					ao.numero_de_omnibus=numero_de_omnibus;
					clrscr();
					printf("Ingrese numero de asientos del omnibus ");scanf("%i",&ao.asientos);
					fwrite(&ao,sizeof(struct altas_omnibus),1,omnibus);
					rewind(omnibus);
					fclose(omnibus);
					}
						if(numero_de_omnibus<0){
						clrscr();
						printf("Error numero de omnibus < 0");
						getch();
						}

					break;
case 4:
FILE *pasajes;
pasajes=fopen("c:\\altapas","ab+");
		if (pasajes==NULL){
		printf(" Error al intentar crear/abrir el archivo");
		getch();
		}else
			{
			clrscr();
			ap.numero_de_pasaje;
			ap.km_hasta_destino=0;
			ap.precio_por_kilometro=0;
			ap.distancia_entre_paradas=0;
			ap.numero_de_omnibus=0;
				clrscr();
				printf(" Ingrese numero de pasaje(0=Salir):");
				scanf("%i",&numero_de_pasaje);
				}
				if(numero_de_pasaje>0){

					rewind(pasajes);
					while(!feof(pasajes)){
					fread(&ap,sizeof(struct altas_pasajes),1,pasajes);
					if(numero_de_pasaje==ap.numero_de_pasaje){

					printf("Ya existe");
					printf("\nVuelva a ingresar un numero de pasaje:");
					scanf("%i",&numero_de_pasaje);
					rewind(pasajes);
					}
					}


				       }if(numero_de_pasaje != 0){
					ap.numero_de_pasaje=numero_de_pasaje;
					clrscr();
					printf("Ingrese numero de omnibus: "); scanf("%i",&ap.numero_de_omnibus);
					clrscr();
					printf("Ingrese los kilometros hasta el destino ");scanf("%i",&ap.km_hasta_destino);
					clrscr();
					printf("Ingrese el precio por kilometros: ");scanf("%i",&ap.precio_por_kilometro);
					clrscr();
					printf("Ingrese la distancia entre paradas(en mts): ");scanf("%i",&ap.distancia_entre_paradas);
					fwrite(&ap,sizeof(struct altas_pasajes),1,pasajes);
					rewind(pasajes);
					fclose(pasajes);
					}
						if(numero_de_pasaje<0){
						clrscr();
						printf("Error numero de pasaje < 0");
						getch();
						}

					break;
}
}


void consultas()
{
int op;
FILE *viajes;
FILE *viajes2;
FILE *viajes3;
struct altas_omnibus co;
struct altas_viajes cv;
struct altas_pasajes cp;
struct altas_recorrido cr;
int numero_de_omnibus;
char nombre[30];
clrscr();
printf("1-Recorrido particular horarios");
printf("\n2-Recorrido particular asientos");
printf("\n3-Omnibus ");
printf("\n4-Chofer o guarda");
printf("\nIngrese una opcion:");
scanf("%i",&op);
switch (op) {
case 1:
clrscr();
printf("Ingrese numero de recorrido:");
scanf("%i",&numero_de_omnibus);
viajes=fopen("c:\\altareco","rb+");
rewind(viajes);
while ( !feof(viajes) ) {
fread(&cr, sizeof(struct altas_recorrido), 1, viajes);
if (numero_de_omnibus == cr.numero_de_recorrido ){
clrscr();
printf("\nNumero de omnibus: %d", cr.numero_de_omnibus);
printf("\nEl origen es: %s" , cr.origen);
printf("\nEl destino es: %s" , cr.destino);
printf("\nPulse una tecla...");
}
}
viajes2=fopen("c:\\altaviaj","rb+");
rewind(viajes2);
while ( !feof(viajes2) ) {
fread(&cv, sizeof(struct altas_viajes), 1, viajes2);
if (cr.numero_de_omnibus == cv.numero_de_omnibus ){
clrscr();
printf("Dia: %d",cv.dia);
printf("\nMes: %d",cv.mes);
printf("\nAnio: %d",cv.anio);
getch();
}
}
break;
case 2:
clrscr();
printf("Ingrese numero de recorrido:");
scanf("%i",&numero_de_omnibus);
viajes=fopen("c:\\altareco","rb+");
rewind(viajes);
while ( !feof(viajes) ) {
fread(&cr, sizeof(struct altas_recorrido), 1, viajes);
if (numero_de_omnibus == cr.numero_de_recorrido ){
clrscr();
printf("\nNumero de omnibus: %d", cr.numero_de_omnibus);
printf("\nEl origen es: %s" , cr.origen);
printf("\nEl destino es: %s" , cr.destino);
printf("\nPulse una tecla...");
}
}
viajes2=fopen("c:\\altaviaj","rb+");
rewind(viajes2);
while ( !feof(viajes2) ) {
fread(&cv, sizeof(struct altas_viajes), 1, viajes2);
if (cr.numero_de_omnibus == cv.numero_de_omnibus ){
clrscr();
printf("Numero de viaje: %d",cv.numero_de_viaje);
}
}
viajes3=fopen("c:\\altabus","rb+");
rewind(viajes3);
while ( !feof(viajes3) ) {
fread(&co, sizeof(struct altas_viajes), 1, viajes3);
if (cv.numero_de_omnibus == co.numero_de_omnibus ){
clrscr();
printf("Numero de asientos: %d",co.asientos);
printf("\nHorario: %d/%d/%d",cv.dia,cv.mes,cv.anio);
printf("\nChofer: %s", cv.chofer);
printf("\nGuarda: %s",cv.guarda);
printf("\nHora del dia: %d:%d",cv.hora,cv.min);
getch();
}
}
case 3:
clrscr();
printf("Ingrese numero viaje:");
scanf("%i",&numero_de_omnibus);
viajes=fopen("c:\\altaviaj","rb+");
rewind(viajes);
while ( !feof(viajes) ) {
fread(&cv, sizeof(struct altas_viajes), 1, viajes);
if (numero_de_omnibus == cv.numero_de_viaje ){
clrscr();
printf("\nNumero de omnibus: %d", cv.numero_de_omnibus);
}
}
viajes2=fopen("c:\\altabus","rb+");
rewind(viajes2);
while ( !feof(viajes2) ) {
fread(&co, sizeof(struct altas_omnibus), 1, viajes2);
if (cv.numero_de_omnibus == co.numero_de_omnibus ){
clrscr();
printf("Asientos disponibles: %d",co.asientos);
printf("\nChofer: %s", cv.chofer);
printf("\nGuarda: %s",cv.guarda);
getch();
}
}
break;
case 4:
clrscr();
printf("Ingrese chofer o guarda:");
scanf("%s",&nombre);
viajes=fopen("c:\\altaviaj","rb+");
rewind(viajes);
clrscr();
while ( !feof(viajes) ) {
fread(&cv, sizeof(struct altas_viajes), 1, viajes);
if ( nombre == cv.chofer ){
printf("\nDia mes anio %d:%d:%d",cv.dia,cv.mes,cv.anio);
}
getch();
}
}
}

void bajas() {
clrscr();
int op, i, numero_de_omnibus, numero_de_pasaje, numero_de_viaje, numero_de_recorrido;
struct altas_viajes av;
struct altas_recorrido ar;
struct altas_omnibus ao;
struct altas_pasajes ap;
printf("1-Viajes");
printf("\n2-Omnibus");
printf("\n3-Recorridos");
printf("\n4-Pasajes");
scanf("%i",&op);
switch (op) {
case 1:

printf("Ingrese el numero de viaje para eliminar viaje");

int numero_de_viaje; scanf("%i",&numero_de_viaje);getchar();

FILE *arch1;

FILE *arch2;

arch1 = fopen("c:\\altaviaj","r+");

arch2 = fopen("c\\altvtemp","ab+");

while(fread(&av,sizeof(altas_viajes),1,arch1)==1){

if ( numero_de_viaje != av.numero_de_viaje) fwrite(&av,sizeof(altas_viajes),1,arch2);

}; 
fclose(arch1);

fclose(arch2);

remove("c:\\altaviaj");

rename("c:\\altvtemp","c:\\altaviaj ");

puts("viaje eliminado");

getchar();


break;
case 2: 

printf("Ingrese el numero de omnibus para eliminar omnibus: ");

int numero_de_omnibus; scanf("%i",&numero_de_omnibus);getchar();

FILE *arch3;

FILE *arch4;

arch3 = fopen("c:\\altabus","r+");

arch4 = fopen("c\\altbtemp","ab+");

while(fread(&av,sizeof(altas_omnibus),1,arch3)==1){

if ( numero_de_omnibus != ao.numero_de_omnibus) fwrite(&av,sizeof(altas_omnibus),1,arch4);

}; 

fclose(arch3);

fclose(arch4);

remove("c:\\altabus");

rename("c:\\altbtemp","c:\\altabus ");


puts("omnibus eliminado");

getchar();

break;
case 3:

printf("Ingrese el numero de recorrido para eliminar recorrido");

int numero_de_recorrido; scanf("%i",&numero_de_recorrido);getchar();

FILE *arch5;

FILE *arch6;

arch5 = fopen("c:\\altareco","r+");

arch6 = fopen("c\\altrtemp","ab+");

while(fread(&ar,sizeof(altas_recorrido),1,arch5)==1){

if ( numero_de_recorrido != ar.numero_de_recorrido) fwrite(&ar,sizeof(altas_recorrido),1,arch6);

};
fclose(arch5);

fclose(arch6);

remove("c:\\altareco");

rename("c:\\altrtemp","c:\\altareco ");

puts("recorrido eliminado");

getchar();

break;
case 4: 

printf("Ingrese el numero de pasaje para eliminar pasaje");

int numero_de_pasaje; scanf("%i",&numero_de_pasaje);getchar();

FILE *arch7;

FILE *arch8;

arch7 = fopen("c:\\altapas","r+");

arch8 = fopen("c\\altptemp","ab+");

while(fread(&ap,sizeof(altas_pasajes),1,arch7)==1){

if ( numero_de_pasaje != ap.numero_de_pasaje) fwrite(&ap,sizeof(altas_pasajes),1,arch8);

};
fclose(arch7);
fclose(arch8);
remove("c:\\altapas");
rename("c:\\altptemp","c:\\altapas ");
puts("recorrido eliminado");
getchar();
break;
}
}

void ventas() {
     clrscr();
     int op, i, numero_de_omnibus, numero_de_pasaje, numero_de_viaje, numero_de_recorrido;
     struct altas_viajes av;
     struct altas_recorrido ar;
     struct altas_omnibus ao;
     struct altas_pasajes ap;
     printf("Menu de ventas ");
     printf("\n 1- Venta de pasajes");
     scanf("%i",&op);
     switch (op) {
	     case 1:
		     FILE *pasajes;
		     FILE *pasajes2;
		     pasajes=fopen("c:\\altapas","ab+");
		     printf(" Ingrese numero de pasaje(0=Salir):");
		     int numero_de_pasaje_ventas;
		     scanf("%i",&numero_de_pasaje_ventas);
		     rewind(pasajes);
		     while(!feof(pasajes)){
			     fread(&ap,sizeof(struct altas_pasajes),1,pasajes);
			    }
				     if(numero_de_pasaje_ventas==ap.numero_de_pasaje){
				     pasajes2=fopen("c:\\ventas","ab+");
				     fwrite(&ap,sizeof(struct altas_pasajes),1,pasajes2);
				     fclose(pasajes);
				     fclose(pasajes2);
				     FILE* arch7;
				     FILE* arch8;
									 arch7=fopen("c:\\altapas","r+");
				     arch8=fopen("c\\altptemp","ab+");

						while(fread(&ap,sizeof(altas_pasajes),1,arch7)==1){
						if ( numero_de_pasaje != ap.numero_de_pasaje) fwrite(&ap,sizeof(altas_pasajes),1,arch8);
						};
						fclose(arch7);
						fclose(arch8);
						remove("c:\\altapas");
						rename("c:\\altptemp","c:\\altapas ");
						puts("recorrido eliminado");
						getchar();
													 }else{
															 printf("No se pudo escribir ventas");
															 getch();
														}

										break;
				}
 }









  void listados()
{
int op;
FILE *viajes;
FILE *viajes2;
FILE *viajes3;
struct altas_omnibus co;
struct altas_viajes cv;
struct altas_pasajes cp;
struct altas_recorrido cr;
int numero_de_omnibus, control;
clrscr();
printf("1-Viajes realizados");
printf("\n2-Recorridos");
printf("\nIngrese una opcion:");
scanf("%i",&op);
switch (op) {
case 1:
clrscr();
viajes=fopen("c:\\altaviaj","rb+");
rewind(viajes);
while ( !feof(viajes) ) {
fread(&cv, sizeof(struct altas_viajes), 1, viajes);
printf("\nDia mes anio %d:%d:%d  Numero de omnibus: %d   Numero de viaje: %d",cv.dia,cv.mes,cv.anio,cv.numero_de_omnibus,cv.numero_de_viaje);
printf("\n***************************************************************");
}
getch();
break;
case 2:
clrscr();
viajes=fopen("c:\\altareco","rb+");
rewind(viajes);
while ( !feof(viajes) ) {
fread(&cr, sizeof(struct altas_recorrido), 1, viajes);
printf("\n\nNumero de recorrido: %d  Numero de omnibus: %d Origen: %s  Destino: %s  \nCantidad de paradas intermedias: %d",cr.numero_de_recorrido,cr.numero_de_omnibus,cr.origen,cr.destino,cr.cantidad_de_paradas_intermedias);
printf("\n*******************************************************************************");
}
getch();
}
}










