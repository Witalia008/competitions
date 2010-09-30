program tigra;
{$APPTYPE CONSOLE}

function dob(n:int64):int64;
var
  i:int64;
begin
  i:=0;
  while n >0 do
    begin
      i:=i+(n mod 10)*(n mod 10);
      n:=n div 10;
    end;
  dob:=i;
end;

var
  i,n:longword;
  a,b:int64;
  mas:array[0..2000]of boolean;
  fl:boolean;
begin
  assign(input,'input.txt');
  reset(input);
  assign(output,'output.txt');
  rewrite(output);
  read(n);
  for i:=1 to n do
    begin
      read(a);
      b:=a;
      fl:=true;
      fillchar(mas,sizeof(mas),0);
      a:=dob(a);
      while a>1 do
        begin
          if mas[a] then
            begin
              fl:=false;
              break;
            end;
          mas[a]:=true;
          a:=dob(a);
        end;
      if (fl)and(a<>0) then write(1) else write(0);
    end;
  writeln;
  close(input);
  close(output);
end.
