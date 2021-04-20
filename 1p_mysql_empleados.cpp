#include <mysql.h>
#include <string>
#include <iostream>
using namespace std;
int q_estado;
int main()
{
	MYSQL* conectar;
	conectar = mysql_init(0);
	conectar = mysql_real_connect(conectar, "localhost", "root", "RYMARI03816*", "db_empleados", 3306, NULL, 0);
	if (conectar) {
		cout << "Conexion correcta..." << endl;

		string nombres, apellidos, direccion, telefono, dpi, genero, fecha_nacimiento, idPuesto, fecha_inicio_labores, fecha_ingreso;
		cout << "Ingrese Nombre: ";
		cin >> nombres;
		cout << "Ingrese Apellidos: ";
		cin >> apellidos;
		cout << "Ingrese Direccion: ";
		cin >> direccion;
		cout << "Ingrese Telefono: ";
		cin >> telefono;
		cout << "Ingrese DPI: ";
		cin >> dpi;
		cout << "Ingrese Genero: ";
		cin >> genero;
		cout << "Ingrese fecha de nacimiento: ";
		cin >> fecha_nacimiento;
		cout << "Ingrese Id del Puesto: ";
		cin >> idPuesto;
		cout << "Ingrese Fecha de inicio de labores";
		cin >> fecha_inicio_labores;
		cout << "Ingrese Fecha de ingreso: ";
		cin >> fecha_ingreso;

		string insert = "insert into empleados (nombres, apellidos, direccion, telefono, dpi, genero, fecha_nacimiento, idPuesto, fecha_inicio_labores, fecha_ingreso) values('" + nombres + "', '" + apellidos + "', '" + direccion + "', '" + telefono + "', '" + dpi + "', '" + genero + "', '" + fecha_nacimiento + "', '" + idPuesto + "', '" + fecha_inicio_labores + "', '" + fecha_ingreso + "')";
		const char* i = insert.c_str();
		q_estado = mysql_query(conectar, i);
		if (!q_estado) {
			cout << "Se ingreso exitosamente..." << endl;
		}
		else {
			cout << "No se pudo conectar..." << endl;
		}

		string consulta = "select * from db_empleados.empleados";
		const char* c = consulta.c_str();
		q_estado = mysql_query(conectar, c);
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		if (!q_estado) {
			resultado = mysql_store_result(conectar);

			while (fila = mysql_fetch_row(resultado)) {
				cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << fila[6] << "," << fila[7] << "," << fila[8] << "," << fila[9] << "," << fila[10] << "," << fila[11] << endl;
			}
		}
		else {
			cout << "Error al intentar ingresar... " << endl;
		}

		string i;
		cout << "Ingrese el id de Empleado que desea eliminar: ";
		cin >> i;
		string eliminar = "delete from db_empleados.empleados where idEmpleado= 'i'";
		const char* f = eliminar.c_str();
		q_estado = mysql_query(conectar, f);

		if (!q_estado) {
			cout << "Se elimino exitosamente..." << endl;
		}
		else {
			cout << "No se pudo eliminar..." << endl;
		}

	}
	else {
		cout << "Error en la matriz..." << endl;
	}
	system("pause");
	return 0;