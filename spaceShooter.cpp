// SPACE SHOOTER - NACHO DEV

#include <windows.h>
#include <iostream>
#include <conio.h>

#define IZQUIERDA 75
#define DERECHA   77


using namespace std;



// DIBUJO AVION
char avion_l1[]={' ',' ',' ', '*',' ',' ',' ',0};          
char avion_l2[]={' ',' ','*', '*','*',' ',' ',0};
char avion_l3[]={' ','*',' ', '*',' ','*',' ',0};


// DIBUJO EXPLOSION
char explosion_l1[]={' ',' ','*','*',' ',' ',' ',0};      
char explosion_l2[]={' ','*','*','*','*',' ',' ',0};
char explosion_l3[]={' ',' ','*','*',' ',' ',' ',0};

// DIBUJO EXPLOSION
char explosion_r1[]={'*',' ','*','*',' ','*',' ',0};       
char explosion_r2[]={' ','*','*','*','*',' ',' ',0};
char explosion_r3[]={'*',' ','*','*',' ','*',' ',0};

// BORRADOR DE AVION
char borrar_avion[]={' ',' ',' ',' ',' ',' ',' ',0};


int Num_vidas = 3;
int Corazones = 3;


int ix = 40;
int iy = 19;


int y = 8, x = 12;   // coord primer asteroide
int yy = 12, xx = 17; // coord segundo asteroide
int y1 = 6, x1 = 58;  // coord tercer asteroide
int y2 = 9 , x2 = 70;  // coord cuarto asteroide


int i, v;  // var de los bucles

// (1)- CREAMOS LA VAR PARA LAS BALAS DE LA NAVE ------------------------------------------------------------------------------------------------------ 

int dd = 0, dd1 = 0, dd2 = 0, dd3=0, dd4=0;

bool disparo = false;  // (2)- CONSEJO: cuando querramos usar una var que sea para activar algo con una tecla, conviene usar bool 




// (6)- Creamos otra variable para evitar que la bala se mueva con la nave --------------------------------------------------------------------------------------------------


int xb, xb1, xb2, xb3, xb4;



// var para rutina de cambio de nivel
int repeticion = 0, nivel = 1;
bool condicion = false;


void gotoxy (int x, int y){  
	
	HANDLE hCon;
	COORD dwPos;
	
	dwPos.X = x;
	dwPos.Y = y;
	
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hCon, dwPos);
}
	
	
	
	
	void vidas (int vi){
		
		gotoxy (2, 1);  // Esto nos sitúa en la parte del eje x e y (x=2, y=1)
		printf ("VIDAS %d", vi);  // acá ponemos que imprima la palabra VIDAS y el %d significa que queremos imprimir un nro entero, y el vi
		//                           es el nro que va a usar la var para ir contando vidas
		
	}
		
		
		void Barra_salud (int n){
			
			gotoxy (72, 1); printf (" ");   
			gotoxy (73, 1); printf (" ");
			gotoxy (74, 1); printf (" ");
			
			for (v = 0; v<n; v++){   
				gotoxy (72+v, 1);  // parte de la pos base y cuando va creciendo va imprimiendo corazones
				printf ("%c", 3);      // el %c es para indicar que ahí se quiere imprimir un char, que en codigo ascii el 3 es el dibujo del corazón
				
			}
			
		}
			
			
			
			void Explosion (void){
				
				gotoxy (ix, iy); puts (explosion_l1);
				gotoxy (ix, iy+1); puts (explosion_l2);
				gotoxy (ix, iy+2); puts (explosion_l3);
				
				Sleep (380); // esto sirve para poder retardar la animación para que no se desactive automáticamente (la S de Sleep va en MAYUS)
				
				
				gotoxy (ix, iy); puts (explosion_r1);
				gotoxy (ix, iy+1); puts (explosion_r2);
				gotoxy (ix, iy+2); puts (explosion_r3);
				
				Sleep (380);
				
				gotoxy (ix, iy); puts (avion_l1);
				gotoxy (ix, iy+1); puts (avion_l2);
				gotoxy (ix, iy+2); puts (avion_l3);
				
			}//fin void Explosion
				
				
				
				void jugar (void){
					
					
					// pos bala 1
					if (!disparo){   // (7)- con esto lo que hacemos es que vamos a reemplazar el valor de xb con la de la nave en ese momento, así ya nos queda guardada la pos en x 
						//              y se mueve solo en ese lugar 
						xb = ix;  
					}
					
					//pos bala 2
					if (!disparo){ 
						xb1 = ix-1; 
					}
					
					//pos bala 3
					if (!disparo){ 
						xb4 = ix-2;  
					}
					
					//pos bala 4
					if (!disparo){ 
						xb3 = ix+2;  
					}
					//pos bala 5
					if (!disparo){ 
						xb2 = ix+1;  
					}
					
					
					// (3)- PINTAMOS EL ASTERISCO ENCIMA DE LA NAVE PARA INICIALIZAR LA BALA --------------------------------------------------------------------------
					
					//BALA
					//  gotoxy (ix+3, iy+dd); printf ("*"); // con esto pintamos la bala (en el tuto lo hace antes, y luego lo corrige, por eso está escrito acá primero y desps más abajo otra vez, ya con las coordenadas que corresponden
					
					// (8)- Reemplazamos ix por xb 
					
					gotoxy (xb+3, iy+dd); printf ("*");
					gotoxy (xb1+3, iy+dd1); printf ("*");
					gotoxy (xb2+3, iy+dd2); printf ("*");
					gotoxy (xb3+3, iy+dd3); printf ("*");
					gotoxy (xb4+3, iy+dd4); printf ("*");
					
					
					
					
					// RUTINA DE ASTEROIDES 
					
					gotoxy (x, y);   printf ("%c", 2);   // ponemos la coordenada relacionada al primer asteroide 
					gotoxy (xx, yy); printf ("%c", 2); 
					gotoxy (x1, y1); printf ("%c", 2); 
					gotoxy (x2, y2); printf ("%c", 2); 
					
					Sleep (70);
					
					
					// con esto vamos borrando los asteroide para que se dejen de ver en el lugar
					gotoxy (x, y);     printf (" ");   
					gotoxy (xx, yy);   printf (" ");   
					gotoxy (x1, y1);   printf (" ");
					gotoxy (x2, y2);   printf (" ");   
					
					
					//BALA
					//gotoxy (ix+3, iy+dd); printf (" "); // con esto borramos la bala  (acá lo mismo que más arriba, la coordenada cambia por xb)
					
					gotoxy (xb+3, iy+dd); printf (" "); 
					gotoxy (xb1+3, iy+dd1); printf (" ");
					gotoxy (xb2+3, iy+dd2); printf (" ");
					gotoxy (xb3+3, iy+dd3); printf (" ");
					gotoxy (xb4+3, iy+dd4); printf (" ");
					
					
					
					//
					
					// (4)- Vamos poniendo un if para que la bala se vaya moviendo en el mapa -----------------------------------------------------------------------------------------------
					
					if (disparo == true) {dd--; dd1 --; dd2--; dd3--; dd4--;}
					
					
					
					
					
					if (iy+dd < 5 ){   // con esto se resetea la bala y vuelve al inicio con la nave
						
						dd=0;
						disparo = false; 
						
					}
					
					if (iy+dd1 < 5 ){   
						
						dd1=0;
						disparo = false; 
						
					}
					
					if (iy+dd2 < 5 ){   
						
						dd2=0;
						disparo = false; 
						
					}
					if (iy+dd3 < 5 ){   
						
						dd3=0;
						disparo = false; 
						
					}
					if (iy+dd4 < 5 ){   
						
						dd4=0;
						disparo = false; 
						
					}
					
					// (9)- ACÁ EN LA CONDICIÓN AGREGAMOS QUE CUANDO LA BALA PASE POR EL ASTEROIDE, ESTE SE REINICIE -------------------------------------------------------------------------
					
					if (y > 20  || ( (x == xb+3) && (iy + dd <=y)  )  || ( (x == xb1+3) && (iy + dd1 <=y)  ) || ( (x == xb2+3) && (iy + dd2 <=y)  ) || ( (x == xb3+3) && (iy + dd3 <=y)  ) || ( (x == xb4+3) && (iy + dd4 <=y)  ) ){   // asteroide 1  // (10)- lo agregamos dentro de la condición del asteroide para que este se reinicie, y lo hacemos con las condiciones de los 4 asteroides
						
						y = 4;   // este valor lo vuelve hacia arriba del todo 
						x = (rand() % 70) + 6;  // y con este valor, cambiamos la pos x de forma random, tratando de que entre dentro de las 70 casillas correspondientes
						//                         a la pantalla, y le sumamos 6 para poder dejarlo bien centrado en la misma
						
						
						
						if (y==4){
							
							condicion = false;
						}
						
						
					}
					
					
					if (yy > 20|| ( (xx == xb+3) && (iy + dd <= yy)  )  || ( (xx == xb1+3) && (iy + dd1 <=yy)  ) || ( (xx == xb2+3) && (iy + dd2 <=yy)  ) || ( (xx == xb3+3) && (iy + dd3 <=yy)  ) || ( (xx == xb4+3) && (iy + dd4 <=yy)  ) ){// asteroide 2
						
						yy = 4;   // este valor lo vuelve hacia arriba del todo 
						xx = (rand() % 70) + 6; 
						
						if (y==4){
							
							condicion = false;
						}
						
						
					}
					
					
					if (y1 > 20 || ( (x1 == xb+3) && (iy + dd <=y1)  )  || ( (x1 == xb1+3) && (iy + dd1 <=y1)  ) || ( (x1 == xb2+3) && (iy + dd2 <=y1)  ) || ( (x1 == xb3+3) && (iy + dd3 <=y1)  ) || ( (x1 == xb4+3) && (iy + dd4 <=y1)  ) ){ // asteroide 3
						
						y1 = 4;   // este valor lo vuelve hacia arriba del todo 
						x1 = (rand() % 70) + 6; 
						
						if (y==4){
							
							condicion = false;
						}
						
						
					}
					
					
					if (y2 > 20|| ( (x2 == xb+3) && (iy + dd <=y2)  )  || ( (x2 == xb1+3) && (iy + dd1 <=y2)  ) || ( (x2 == xb2+3) && (iy + dd2 <=y2)  )|| ( (x2 == xb3+3) && (iy + dd3 <=y2)  ) || ( (x2 == xb4+3) && (iy + dd4 <=y2)  )  ){ // asteroide 4
						
						y2 = 4;   // este valor lo vuelve hacia arriba del todo 
						x2 = (rand() % 70) + 6; 
						
						if (y==4){
							
							condicion = false;
						}
						
						
					}
					
					
					
					// RUTINA PARA MOVER AVIÓN 
					
					if (kbhit()){ // La función kbhit () es para que eso se ejecute cuando se presiona alguna tecla
						
						unsigned char tecla = getch (); // Esto hace que cuando se presiona una tecla, la variable tecla toma el valor de esa tecla sin apretar enter para que lo lea
						
						switch (tecla){ 
							
						case IZQUIERDA:   // PARA CUANDO APRETAMOS FLECHA IZQUIERDA <-----
							
							if (ix > 4){
								
								gotoxy (ix, iy);   puts (borrar_avion);  // primero se borra el avión de la pos vieja
								gotoxy (ix, iy+1); puts (borrar_avion);
								gotoxy (ix, iy+2); puts (borrar_avion);
								
								ix-=2; // con esto lo movemos un par de veces para la izq (es lo mismo que poner ix = ix -2;
								
								
								
								gotoxy (ix, iy);   puts (avion_l1);
								gotoxy (ix, iy+1);   puts (avion_l2);
								gotoxy (ix, iy+2);   puts (avion_l3);
							}
							break;
							
						case DERECHA:   // PARA CUANDO APRETAMOS FLECHA DERECHA ----->
							
							if (ix < 70){
								
								gotoxy (ix, iy);   puts (borrar_avion);  // primero se borra el avión de la pos vieja
								gotoxy (ix, iy+1); puts (borrar_avion);
								gotoxy (ix, iy+2); puts (borrar_avion);
								
								ix+=2; // con esto lo movemos un par de veces para la izq (es lo mismo que poner ix = ix +2;
								
								
								
								gotoxy (ix, iy);   puts (avion_l1);
								gotoxy (ix, iy+1);   puts (avion_l2);
								gotoxy (ix, iy+2);   puts (avion_l3);
							}
							
							break;
							
							
							
							
							// (5)-  TENEMOS QUE ACTIVAR EN EL SWITCH LA ACCIÓN PARA PODER EFECTUAR EL DISPARO ---------------------------------------------------------------------------------------------
							
							
						case 'd': disparo = true; break;  // con esto ya se puede disparar
						
						
						
						
						
						}// fin switch tecla
						
						
					}// fin if tecla random 
					
					
					// RUTINA PARA GOLPES DE ASTEROIDES
					
					if (  ((x > ix && x < ix+6)  && (y == iy -1)) || ((xx > ix && xx < ix+6)  && (yy == iy -1)) || ((x1 > ix && x1 < ix+6)  && (y1 == iy -1))
						||  ((x2 > ix && x2 < ix+6)  && (y2 == iy -1))  ) // cuando algún asteroide impacta, pasa lo siguiente 
					{
						
						Corazones --; // cuando pasa esto, se disminuyen el nro de corazones
						
						Barra_salud (Corazones);  // la barra salud imprime el nro de Corazones que nos quedan
						
						printf ("\a");  //con esto emitimos un sonidito 
						
						
					}// fin del if de impacto de asteroides 
					
					
					gotoxy (ix, iy);   puts (avion_l1);
					gotoxy (ix, iy+1);   puts (avion_l2);
					gotoxy (ix, iy+2);   puts (avion_l3);
					
					
					
					if (Corazones == 0) // También se puede poner como if (!Corazones) que es como decir cuando NO Corazones o la negación de Corazones
					{
						
						Num_vidas--;  // num vidas decrece
						
						vidas(Num_vidas);  // en VIDAS sale el num de vidas restante
						
						Explosion();   // tamb se ejecuta una explosión 
						
						Corazones= 3;  // se resetea el nro de Corazones
						
						Barra_salud (Corazones);  // se reimprime la barra de salud
						
					}// fin if pérdida de vidas
					
					
					
					// RUTINA PARA CAMBIO DE NIVEL
					
					if (!condicion) // como condicion es falso, cuando lo negamos estamos diciendo que es verdadero, por ende se ejecuta el cuerpo del if cuando sea true condicion 
					{
						repeticion ++;
						
						condicion = true; // si no hacemos que sea verdad, habrá un cambio de nivel muy rápido
						
						
					}
					
					if (repeticion == 4){  // si aumentamos el número, el nivel va a durar mucho más 
						
						nivel ++;
						
						gotoxy(35, 1); printf ("NIVEL %i", nivel);  // el %i es para imprimir un numero entero, pero antes ubicamos el lugar donde se va a 
						//                                             imprimir eso gracias a gotoxy
						
						
						
						//borrado
						gotoxy( ix, iy); puts (borrar_avion);
						gotoxy( ix, iy+1); puts (borrar_avion);
						gotoxy( ix, iy+2); puts (borrar_avion);
						
						
						//restamos dos a iy para que el avión suba (mientras más tenga y, más abajo va a estar el avión)
						iy -= 2; // iy= iy -2;  ojo con dejar un espacio cuando ponemos el var -= o var +=     var - = ---> así NO!
						
						
						// impresion 
						gotoxy( ix, iy); puts (avion_l1);
						gotoxy( ix, iy); puts (avion_l2);
						gotoxy( ix, iy); puts (avion_l3);
						
						
						repeticion = 0;  // reiniciamos el contador para que se vuelva a contabilizar todos los asteroides
						
						
					}
					
					
					y++; 
					yy++; 
					y1++; 
					y2++;  // con esto vamos incrementando la coordenada para que caigan
					
					
				}// Fin función jugar 
					
					
					
					int main (){
						
						vidas (Num_vidas);  // Con esto invocamos la función vidas para mostrar las vidas en pantalla
						
						Barra_salud (Corazones); // Con esta función se imprimen los corazones
						
						gotoxy(35, 1); printf ("NIVEL %i", nivel);
						
						gotoxy (ix, iy);   puts (avion_l1);
						gotoxy (ix, iy+1);   puts (avion_l2);
						gotoxy (ix, iy+2);   puts (avion_l3);
						
						
						
						while (Num_vidas > 0  && nivel <= 6){ 
							jugar ();
							
							
						}// fin while que ejecuta el juego (se pueden omitir los corchetes en este caso)
						
						cout<<"\n\n\n\t GAME OVER!!!"<<endl<<endl;  // podemos poner el gotoxy para poder elegir bien el lugar de impresión del GAME OVER
						
						
						
						Sleep (200);  // ponemos esto para que espere bastante el juego antes de cerrarse 
						getch ();
						return 0;
						
					}
						
						
						
						
						
