/*
Autor:	Luis Carreto 
fecha:	22/7/2017
Descripcion:	Programa para verificar la sintaxis simple de un documento HTML
Version:	Beta 0.4   Compilado en (g++ version 5.4.0 20160609 (Debian 5.4.0-6))
*/


/*
----------TABLA DE VERDAD DE ERRORES-------------------------

	INICIO 	FIN
	____________
	|  0  |  0  |-- No se declaro la etiqueta  se utiliza el  else
	|  0  |  1  |-- Se finalizo la etiqueta, pero nunca se aperturo
	|  1  |  0  |-- No se finalizo la etiqueta
	|__1__|__1__|--	No Problem

*/

#include<iostream>
#include<fstream>

using namespace std;
int n=0;
bool head_start =true, head_end =true, html_s =true, html_e =true, my_h =true, body_s =true, title_s=true, body_e=true, title_e=true, error=true;

int main()
{


cout<<"██╗  ██╗████████╗██╗     ███╗   ███╗              ███████╗██████╗ ██████╗  ██████╗ ██████╗ ██╗██╗"<<endl;
cout<<"██║  ██║╚══██╔══╝██║     ████╗ ████║              ██╔════╝██╔══██╗██╔══██╗██╔═══██╗██╔══██╗██║██║"<<endl;
cout<<"███████║   ██║   ██║     ██╔████╔██║    █████╗    █████╗  ██████╔╝██████╔╝██║   ██║██████╔╝██║██║"<<endl;
cout<<"██╔══██║   ██║   ██║     ██║╚██╔╝██║    ╚════╝    ██╔══╝  ██╔══██╗██╔══██╗██║   ██║██╔══██╗╚═╝╚═╝"<<endl;
cout<<"██║  ██║   ██║   ███████╗██║ ╚═╝ ██║              ███████╗██║  ██║██║  ██║╚██████╔╝██║  ██║██╗██╗"<<endl;
cout<<"╚═╝  ╚═╝   ╚═╝   ╚══════╝╚═╝     ╚═╝              ╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═╝╚═╝╚═╝"<<endl;
cout<<"This is a program which analyzes the html file to check if there are syntax errors, made as a fucking project for the UMG."<<endl;
cout<<""<<endl;

	string nfichero;
	char letra;

	cout<<"Ingresa el nombre del documento [por ejemplo index]: ";
	cin>>nfichero;

		if (nfichero!="")
			{nfichero+=".html";	}


        ifstream fichero;			//declaramos una variable de tipo fichero


        fichero.open(nfichero.c_str());


/*		TRABAJANDO EN LA PARTE DEL ERROR SI EL ARCHIVO NO SE ABRE
	fichero.open(nfichero.c_str());

	        if (fichero.fail())
        {cerr <<"xxxx";
	exit(1);
}

*/

	if (!fichero.fail()){

/******************************EN ESTE PUNTO SE OBTIENE EL VALOR HACIA EL CARACTER************************/


		while (!fichero.eof()){
//			cout << letra;

		fichero.get(letra);

	if (letra == '<')
	{	fichero.get(letra);

		switch(letra)
		{
		case 'h':
			fichero.get(letra);
			switch(letra)
			{

				case 'e':
					fichero.get(letra);
					if (letra =='a')
					{

						fichero.get(letra);
						if (letra == 'd')
						{
							fichero.get(letra);
							if(letra == '>')
							head_start=false;

						}
					}
					break;

				case 't':


                                        fichero.get(letra);
					if(letra =='m')
					{
						fichero.get(letra);
						if(letra =='l')
						{
                                                       fichero.get(letra);
                                                       if(letra == '>')

							html_s=false;
						}
					}

					break;

			}
		break;



		case 'b':
			fichero.get(letra);
			if (letra =='o')
			{
				fichero.get(letra);
				if(letra =='d')
				{
					fichero.get(letra);
					if(letra =='y')
					{
						fichero.get(letra);
	                                        if(letra =='>')

						body_s=false;
					}
				}
			}
		break;


		case 't':
                        fichero.get(letra);
                        if(letra =='i')
			{
	                        fichero.get(letra);
	                        if(letra =='t')
	                        {
					fichero.get(letra);
                                        if(letra =='l')
					{
		                                fichero.get(letra);
		                                if(letra =='e')
        	                                {
                	                                fichero.get(letra);
                        	                        if(letra =='>')
                                	               { 
                                        	        title_s=false;}
  	                                     	 }
					}

				}
			}

		break;



		case '/':


		fichero.get(letra);

		switch(letra)
		{
		case 'h':
			fichero.get(letra);
			switch(letra)
			{

				case 'e':
					fichero.get(letra);
					if (letra =='a')
					{

						fichero.get(letra);
						if (letra == 'd')
						{
							fichero.get(letra);
							if(letra == '>')
							head_end=false;

						}
					}
					break;

				case 't':


                                        fichero.get(letra);
					if(letra =='m')
					{
						fichero.get(letra);
						if(letra =='l')
						{
                                                       fichero.get(letra);
                                                       if(letra == '>')

							html_e=false;
						}
					}

					break;

			}
		break;



		case 'b':
			fichero.get(letra);
			if (letra =='o')
			{
				fichero.get(letra);
				if(letra =='d')
				{
					fichero.get(letra);
					if(letra =='y')
					{
						fichero.get(letra);
	                                        if(letra =='>')
						
						body_e=false;
					}
				}
			}
		break;


		case 't':
                        fichero.get(letra);
                        if(letra =='i')
			{
	                        fichero.get(letra);
	                        if(letra =='t')
	                        {
					fichero.get(letra);
                                        if(letra =='l')
					{
		                                fichero.get(letra);
		                                if(letra =='e')
        	                                {
                	                                fichero.get(letra);
                        	                        if(letra =='>')
                                	               { 
                                        	        title_e=false;}
  	                                     	 }
					}

				}
			}

		break;

	}


		break;
/*
		case 'H':
			my_h=false;
			cout<<"verifica que el head o el html no esten escritos en MAYUSCULAS"<<endl;
		break;*/

		}

	}


/*********************************************************************************************************/
	}

	fichero.close();
	}

        else {cout <<"error";}


	 if (head_start==true && head_end==true)
	{
		cout<<"[!] Error no se declaro la etiqueta <head>"<<endl;
	}
	else if (head_start==false && head_end==true)
	{
		cout<<"[!] Error No se finalizo la etiqueta <head>, utiliza </etiqueta> para cerrar las etiquetas"<<endl;
	}
	else if (head_start==true && head_end==false)
	{
		cout<<"[!] Error Se finalizo la etiqueta <head>, pero nunca se declaro"<<endl;
	}



	 if (html_s==true && html_e==true)
	{
		cout<<"[!] Error no se declaro la etiqueta <html>"<<endl;
	}
	else if (html_s==false && html_e==true)
	{
		cout<<"[!] Error No se finalizo la etiqueta <html>, utiliza </etiqueta> para cerrar las etiquetas"<<endl;
	}
	else if (html_s==true && html_e==false)
	{
		cout<<"[!] Error Se finalizo la etiqueta <html>, pero nunca se inicio"<<endl;
	}
	else 
	{error=false;
	}


	 if (body_s==true && body_e==true)
	{
		cout<<"[!] Error no se declaro la etiqueta <body>"<<endl;
	}
	else if (body_s==false && body_e==true)
	{
		cout<<"[!] Error No se finalizo la etiqueta <body>, utiliza </etiqueta> para cerrar las etiquetas"<<endl;
	}
	else if (body_s==true && body_e==false)
	{
		cout<<"[!] Error Se finalizo la etiqueta <body>, pero nunca se inicio"<<endl;
	}
	else 
	{error=false;
	}

	 if (title_s==true && title_e==true)
	{
		cout<<"[!] Error no se declaro la etiqueta <title>"<<endl;
	}
	else if (title_s==false && title_e==true)
	{
		cout<<"[!] Error No se finalizo la etiqueta <title>, utiliza </etiqueta> para cerrar las etiquetas"<<endl;
	}
	else if (title_s==true && title_e==false)
	{
		cout<<"[!] Error Se finalizo la etiqueta <title>, pero nunca se inicio"<<endl;
	}
	else 
	{error=false;
	}

	if (error == false)
	{
		cout<<"\n [+] No se detectaron errores de 'sintasix' !!! \n\n"<<endl;
	} 
return 0;
}
