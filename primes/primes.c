#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <postgresql/libpq-fe.h>

int find_prime(unsigned long int x);
unsigned long int get_last_found(PGconn *conn);

void main(){
	unsigned long int x;
	PGconn *conn;

	char query_string[42949];
	printf("Prime searcher running...\n"); 

	conn = PQconnectdb("user=postgres password=hunter2 dbname=math host=localhost");

	 if (PQstatus(conn) == CONNECTION_BAD) {
		 fprintf(stderr, "Connection to database failed: %s\n",
            	PQerrorMessage(conn));
    	}

	x = get_last_found(conn) + 2;
	//database starts at three so don't need to worry about it being odd
	while(1){
		if(find_prime(x)){
			printf("%lu\n",x);
			sprintf(query_string,"INSERT INTO primes (prime_number) VALUES (%lu);",x);
			PGresult *res = PQexec(conn, query_string);
		}
		x = x + 2;
	}
}

unsigned long int get_last_found(PGconn *conn){
	unsigned long int x;
       char* y;
	 PGresult *res = PQexec(conn, "SELECT MAX(prime_number) from primes");
	 PQnfields(res);
	 y = PQgetvalue(res,0,0);
	 x = atoi(y);
	 printf("%s %lu\n",y,x);	 
	 return x;
}


int find_prime(unsigned long int x){
	 unsigned long int i;
	 
	if (x == 2 || x == 3 || x == 5) {
		return 1;
	}
	else if ( x % 2 == 0 || x % 3 == 0 || x % 5 == 0){
		return 0;
	}
	// not sure if bug or 
	else {

		i = 7;
		while(i <= ( unsigned long int) floor(sqrt(x))) {
			if(x % i == 0){
				return 0;
			}
				i = i + 2;
		} 
	}
	
	return 1;
}
