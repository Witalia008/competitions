program mountain;
{$APPTYPE CONSOLE}
var
  mas:array[0..11,0..21]of char;
  n:byte;

procedure srch(i,j:byte);
var
  k,l,n1:byte;
  fl:boolean;
begin
  if (i=n)and(j=2*n) then
    begin
      n1:=0;
      fl:=true;
      while fl do
        begin
          inc(n1);
          for k := 1 to 2*n do
            if mas[n1][k]<>' ' then fl:=false;
        end;
      if mas[n][n*2]='\' then
        begin
          write('+');
          for k:=1 to 2*n do write('-');
          writeln('+');
          for k := n1 to n do
            begin
              write('|');
              for l := 1 to 2*n do
                write(mas[k][l]);
              writeln('|');
            end;
          write('+');
          for k:=1 to 2*n do write('-');
          writeln('+');
        end;
    end else
    begin
      if mas[i][j]='/' then
        begin
          if (i>1)and(j<n*2) then
            begin
              mas[i-1][j+1]:='/';
              srch(i-1,j+1);
              mas[i-1][j+1]:=' ';
            end;
          if j<n*2 then
            begin
              mas[i][j+1]:='\';
              srch(i,j+1);
              mas[i][j+1]:=' ';
            end;
        end;
      if mas[i][j]='\' then
        begin
          if j<n*2 then
            begin
              mas[i][j+1]:='/';
              srch(i,j+1);
              mas[i][j+1]:=' ';
            end;
          if (i<n)and(j<n*2) then
            begin
              mas[i+1][j+1]:='\';
              srch(i+1,j+1);
              mas[i+1][j+1]:=' ';
            end;
        end;
    end;
end;

begin
  assign(input,'mountain.dat');
  reset(input);
  assign(output,'mountain.res');
  rewrite(output);
  read(n);
  fillchar(mas,sizeof(mas),' ');
  mas[n][1]:='/';
  srch(n,1);
  close(input);
  close(output);
end.
