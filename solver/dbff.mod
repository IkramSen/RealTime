param n; #nombre de taches
param m; #nombre de taches
param H; #Hyperperiod
param t{i in 1..n, j in 1..m};

#variable C temps de calcule a cherche
var C{1..n} integer; 


#objectif

maximize U :sum {i in 1..n} C[i]/t[i,2];

#contraintes

subject to
capacite : sum {i in 1..n} C[i]/t[i,2] <= 1;

supp {i in 1..n} : C[i] >=0;
inf {i in 1..n} :  C[i] <= t[i,1];

dbf {inst in 0..H} : sum {i in 1..n} C[i]*floor((inst+t[i,2]-t[i,1])/t[i,2]) <= H;


printf "---Debut de la resolution ---\n";

solve;

printf "---Fin de la resolution ---\n";


display C;
end;

