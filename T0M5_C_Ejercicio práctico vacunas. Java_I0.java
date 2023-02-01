package vacunas;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.time.LocalDate;
import java.time.Period;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

public class Vacuna {
	
	public static void main(String[] args) throws IOException, ParseException {
		
        //Notar que readLine() nos obliga a declarar IOException
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); //Ya tenemos el "lector"

        System.out.println("Número de fechas de nacimiento que vas a registrar:");//Se pide un dato al usuario

        int numFechas = Integer.parseInt(br.readLine());
        
        List <String>listaFechas = new ArrayList();
        
        DateFormat formateador= new SimpleDateFormat("dd/MM/yyyy");

        for(int i = 0; i < numFechas; i++){

            System.out.println("Por favor ingrese la fecha de nacimiento " + (i+1) + " en el siguiente formato dd/mm/aaaa: ");//Se pide un dato al usuario

            String fecha = br.readLine(); //Se lee el nombre con readLine() que retorna un String con el dato
    
            listaFechas.add((fecha));
    
            //Notese que readLine siempre retorna String y la clase BufferedReader...
            //no tiene un metodo para leer enteros, ase que debemos convertirlo.
    
           // int edad = Integer.parseInt(entrada);//Se transforma la entrada anterior en un entero
            //Si el usuario ingreso solo numeros funcionara bien, de lo contrario generara una excepcix

        }

      ImprimeTexto(listaFechas);

    }

	private static void ImprimeTexto(List<String> listaFechas) {
		// TODO Auto-generated method stub
		 System.out.println("Imprimiremos los resultados de acuerdo a las fechas ingresadas. ");
		
		 DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd/MM/yyyy");
		 LocalDate fechaNacimiento = null;
		 
		 for (int i = 0; i<listaFechas.size();i++) {
			 
			 System.out.println("La fecha de nacimiento "+(i+1)+": ");
			 
			 fechaNacimiento = LocalDate.parse(listaFechas.get(i), formatter);
			 Period edad = Period.between(fechaNacimiento, LocalDate.now());
			 System.out.println(String.format("Tiene: %d años, %d meses y %d días.",
			         edad.getYears(),
			         edad.getMonths(),
			         edad.getDays()));
			 
			 if(edad.getYears()>65) {
				 System.out.println("Es candidato para vacunarse");
			 }else if(edad.getYears() == 64 && edad.getMonths() >= 6){
				 System.out.println("Está en lista de espera.");
			 }else {
				 System.out.println("No es candidato para la vacuna.");
			 }
		 }
	
	
	}
}
