/*La Unicef desea obtener información estadística sobre las guarderias ubicadas
en el territorio guatemalteco, dado que por cada niño se ingresa la siguiente información:
 Nombre, Sexo, Edad, Nombre de Guarderia, Departamento (ubicacion geográfica)

Para lo cual se debe generar los siguientes reportes:
a) Porcentaje de niños ubicados en el departamento de guatemala, respecto al total del país.
b) Número de niños por grupo, los cuales se definen con base en la edad,
 teniendo en cuenta lo siguiente:

Grupo 1: Edad menor a 1 año
Grupo 2: Edad comprendida entre 1 y 3 años
Grupo 3: Edad comprendida entre 4 y 6 años
Grupo 4: Edad mayor de 6 años
c) Establecer el grupo que tiene la mayor cantidad de niños.*/

#include <iostream>
#include <vector>
#include <string>
using namespace std; 
//Declaracion de la estructura conforme a la informacion de los niños; 
struct informacion{
	string nombre;
	string sexo; 
	int edad; 
	string nombre_guarderia; 
	int departamento; 	
}; 

vector<informacion> *registro, var_reg;


struct departamentos{
	string nombre;
};

vector<departamentos> *departamento, var_depa;

void pausar_pantalla(){
      // Pause
    string empty;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear buffer before taking new  cout<<"Ingrese sexo"<<endl; 

    cout << "\nPresione enter para continuar \n";
    getline(cin,empty);
};

void limpiar_pantalla(){
  // limpiamos pantalla
  cout << "\033[2J\033[0;0H";
}

void inicio_var(){
	departamento=&var_depa;
  registro=&var_reg;
  
  (*registro).clear();// jaja era esto
  (*departamento).clear();

	departamentos lista_depa[22];

  
  lista_depa[0].nombre="Alta Verapaz";
  lista_depa[1].nombre="Baja Verapaz";
  lista_depa[2].nombre="Chimaltenango";
  lista_depa[3].nombre="Chiquimula";
  lista_depa[4].nombre="El Progreso";
  lista_depa[5].nombre="Escuintla";
  lista_depa[6].nombre="Guatemala";
  lista_depa[7].nombre="Huehuetenango";
  lista_depa[8].nombre="Izabal";
  lista_depa[9].nombre="Jalapa";
  lista_depa[10].nombre="Jutiapa";
  lista_depa[11].nombre="Petén";
  lista_depa[12].nombre="Quetzaltenango";
  lista_depa[13].nombre="Quiché";
  lista_depa[14].nombre="Retalhuleu";
  lista_depa[15].nombre="Sacatepéquez";
  lista_depa[16].nombre="San Marcos";
  lista_depa[17].nombre="Santa Rosa";
  lista_depa[18].nombre="Sololá";
  lista_depa[19].nombre="Suchitepéquez";
  lista_depa[20].nombre="Totonicapán";
  lista_depa[21].nombre="Zacapa";
	
  for (int x=0; x<22; x++){
		(*departamento).push_back(lista_depa[x]);
	}
	
};

void mostrar_depa(){
  cout << "\n";
	departamento=&var_depa;
  for (int x=0; x<(*departamento).size(); x++){
    cout << x+1 << "). " << (*departamento)[x].nombre << "\n";
  }
}

void ingreso(){
  informacion *base, reg_base;
  base=&reg_base;

  cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear buffer before taking new  cout<<"Ingrese sexo"<<endl; 

  cout<<"Ingrese el nombre del niñ@: "<<endl; 
  getline (cin, (*base).nombre);
  
  bool comprobacion=false;
  
  while (comprobacion==false) {
    cout<<"Ingrese su sexo (f/m): "<<endl; 
    getline (cin, (*base).sexo);
    if ((*base).sexo=="f" || (*base).sexo=="F" || (*base).sexo=="m" || (*base).sexo=="M" ) {
    comprobacion=true;
    } else {
    comprobacion=false;
    }
  }
  
  comprobacion=false;
  while (comprobacion==false) {
    cout<<"Ingrese la edad del niñ@ comoprendida entre 0 a 10 años :"<<endl; 
    cin>>(*base).edad;
    if ((*base).edad>=0 && (*base).edad<=10) {
      comprobacion=true;

    } else {
      cout <<"\nLa edad ingresada no esta en el rango aceptable de edad permitida"; 
      pausar_pantalla();
    }
  }
  cin.ignore();
  cout<<"Ingrese nombre de la guarderia"<<endl; 
  getline (cin, (*base).nombre_guarderia); 

  mostrar_depa();
  
  
  while (comprobacion==false){
    cout<<"Ingrese departamento que pertenece la guardería"<<endl; 
    cin >> (*base).departamento;
    (*base).departamento-=1;
    if ((*base).departamento>=0 && (*base).departamento<=22) {
      comprobacion=true;
    } else {
      cout << "Ingreso una opción invalida!! \n";
      cout << "Porfavor intente de nuevo ..  \n";
    }

  }
  // Guardamos el registro en el puntero de tipo vector con estructura-
  (*registro).push_back((*base));
}

void reporte(){
  //registra el puntero
  registro=&var_reg;
  departamento=&var_depa;
  cout << "Nombre \t\t";
  cout << "Sexo \t\t";
  cout << "Edad \t\t";
  cout << "Guarderia \t\t";
  cout << "Departamento \n";
  cout << "============================================================\n\n";
  for (int i=0; i<(*registro).size(); i++){
    cout << (*registro)[i].nombre << "\t\t";
    cout << (*registro)[i].sexo << "\t\t";
    cout << (*registro)[i].edad << "\t\t\t";
    cout << (*registro)[i].nombre_guarderia << "\t\t";
    cout << (*departamento)[(*registro)[i].departamento].nombre << "\n";
  }
}


void reporte_bonito1(){ //Te causo risa verdad!!!!
  //registra el puntero
  registro=&var_reg;
  departamento=&var_depa;
  
  mostrar_depa();
  
  int temp=0;
  bool comprobacion=false;
  while (comprobacion==false) {
    cout << "\n Ingrese que departamento desea ver % con respecto a todos los ingresos: ";
    cin >> temp; 
    temp-=1; 

    if (temp>=0 && temp<=22){
      comprobacion=true;
    } else {
      cout << "Ingreso un dato que incorrecto, vuelva a intentarlo !! \n";
    }

  }
  // Contamos todos los del departamento solicitado
  int temp2=0;
  for (int i=0; i<(*registro).size(); i++){
    if((*registro)[i].departamento==temp) {
      temp2+=1;
    }
  }

  // Sacamos el porcentaje
  int total=0;
  total=(temp2*100)/(*registro).size();

  // mostramos el resultado
  cout << "\n";
  cout << "Porcentaje de niños ubicados en el departamento de " << (*departamento)[temp].nombre << ", respecto al total del país es de " << total <<"%. \n";
}

void reporte_bonito2(){
  //registra el puntero
  registro=&var_reg;
  departamento=&var_depa;

  int grupo1=0, grupo2=0, grupo3=0, grupo4=0;
  for (int i=0; i<(*registro).size(); i++){
    if ((*registro)[i].edad==0){
      grupo1+=1;
    } else if ((*registro)[i].edad>=1 && (*registro)[i].edad<=3 ) {
      grupo2+=1;
    }
      else if ((*registro)[i].edad>=4 && (*registro)[i].edad<=6 ) {
      grupo3+=1;
    } else {
       grupo4+=1;
    }   
  }
  cout << "\n--------------------------------------------- \n";
  cout <<"Grupo 1: Edad menor a 1 año: " << grupo1 << "\n";
  cout <<"Grupo 2: Edad comprendida entre 1 y 3 años: " << grupo2 << "  \n";
  cout <<"Grupo 3: Edad comprendida entre 4 y 6 años: " << grupo3 << " \n";
  cout <<"Grupo 4: Edad mayor de 6 años: " << grupo4 << " \n";
  cout << "\n--------------------------------------------- \n";
  cout <<"El grupo con mayor cantidad de niños es el: ";
  if (grupo1>>grupo2 && grupo1>>grupo3 && grupo1>>grupo4){
    cout << "Grupo 1.";
  } else if (grupo2>>grupo3 && grupo2>>grupo4 && grupo2>>grupo1) {
    cout << "Grupo 2.";
  } else if (grupo3>>grupo4 && grupo3>>grupo1 && grupo3>>grupo2) {
    cout << "Grupo 3.";
  } else {
    cout << "Grupo 4.";
  }
}

void mp(){
	int resp;
	do {
    // limpiamos pantalla
    limpiar_pantalla();
		cout<<"--------Sistema de registro de niños de 0 a 10 años ----------------"<<"\n";
		cout<<" Menu Principal"<<"\n";
		cout<<"-------------------"<<"\n";
		cout<<" 1 - Ingresar registro "<<"\n";
		cout<<" 2 - Reporte "<<"\n";
		cout<<" 3 - Salir"<<"\n";
		cout<<"--------------------------"<<"\n";
		cout<<" Seleccione su opcion: ";
		cin>>resp;
		if (resp==1){		
			  // limpiamos pantalla
      limpiar_pantalla();
			ingreso();
		}
		else if (resp==2){		
      reporte();
      reporte_bonito1();
      reporte_bonito2();
      pausar_pantalla();
		}
		else if (resp==3)
			break;
		else 
			break;
		
	} while(resp!=3);	
}

int main(){
  inicio_var();
	mp();

  return 0;	 
}
