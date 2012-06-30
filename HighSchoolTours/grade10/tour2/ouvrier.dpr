program ouvrier;
{$APPTYPE CONSOLE}
const
  a:array[1..14]of longword=(1,2,5,14,42,132,429,1430,4862,16796,58786,208012,742900,2674440);
var
  n:byte;
begin
  assign(input,'ouvrier.dat');
  reset(input);
  assign(output,'ouvrier.res');
  rewrite(output);
  read(n);
  writeln(a[n div 2]);
  close(input);
  close(output);
end.
