program visimkovi_drobu;
{$APPTYPE CONSOLE}
const
  nmax=100;
type
  tmas=record
         len:longword;
         n:array[1..nmax]of byte;
       end;
procedure div_mod(var a:tmas;b:longword);
var
  i,ost:longword;
  res:tmas;
begin
  ost:=0;
  fillchar(res,sizeof(res),0);
  for i:=1 to nmax do
    begin
      ost:=ost*10+a.n[i];
      res.n[i]:=ost div b;
      ost:=ost mod b;
    end;
  a:=res;
  a.len:=nmax;
  while a.n[a.len]=0 do dec(a.len);
end;

var
  a,b:tmas;
  n,i,j:longword;
  q:char;
begin
  assign(input,'input.txt');
  reset(input);
  assign(output,'output.txt');
  rewrite(output);
  while not eof(input) do
    begin
      i:=0;
      fillchar(a,sizeof(a),0);
      fillchar(b,sizeof(b),0);
      while not eoln(input) do
        begin
          read(q);
          write(q);
          if q<>'.' then
            begin
              inc(i);
              a.n[i]:=ord(q)-48;
            end;
        end;
      write(' [8] = ');
      a.len:=i;
      for i:=a.len downto 2 do
        begin
          b.n[1]:=a.n[i];
          div_mod(b,8);
        end;
      write(b.n[1],'.');
      for i:=2 to b.len do write(b.n[i]);
      writeln(' [10]');
      readln;
    end;
  close(input);
  close(output);
end.
 