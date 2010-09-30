program nikifor_2;
{$APPTYPE CONSOLE}
const
  nmax=20;
var
  x,y,i,n,j,l:longword;
  a,b:array[0..nmax]of longword;
  fl:boolean;
begin
  assign(input,'input.txt');
  reset(input);
  assign(output,'output.txt');
  rewrite(output);
  read(x,y);
  i:=1;
  fl:=false;
  while (i<=x)and(not fl) do
    begin
      inc(i);
      n:=x;
      a[0]:=nmax+1;
      while n>0 do
        begin
          dec(a[0]);
          a[a[0]]:=n mod i;
          n:=n div i;
        end;
      n:=y;
      b[0]:=nmax+1;
      while n>0 do
        begin
          dec(b[0]);
          b[b[0]]:=n mod i;
          n:=n div i;
        end;
      fl:=true;
      l:=nmax;
      for j:=nmax downto b[0] do
        begin
          while (l>=a[0])and(a[l]<>b[j]) do
            dec(l);
          if l<a[0] then
            begin
              fl:=false;
              break;
            end else dec(l);
        end;
    end;
  if fl then writeln(i) else writeln('No solution');
  close(input);
  close(output);
end.
