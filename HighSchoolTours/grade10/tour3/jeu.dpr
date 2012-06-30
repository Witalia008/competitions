program jeu;
{$APPTYPE CONSOLE}
const
  nmax=50;
type
  tmas=array[1..nmax]of record
                          p,k:byte;
                        end;
var
  sol,a:tmas;
  n:word;
  used,u:array[1..nmax]of boolean;

procedure srch(pp,kk,k,i:word);
var
  j,c:word;
  fl,f:boolean;
begin
  sol[i].p:=pp;
  sol[i].k:=kk;
  used[k]:=true;
  if i=n then
    begin
      fl:=true;
      if fl then
        begin
          write(sol[1].p,':',sol[1].k);
          for j:=2 to n do
            write(' ',sol[j].p,':',sol[j].k);
          writeln;
        end;
    end else
    begin
      for j:=1 to n do
        if (not used[j]) then
          begin
            if (a[j].p=kk) then srch(a[j].p,a[j].k,j,i+1);
            if (a[j].k=kk)and(a[j].k<>a[j].p) then srch(a[j].k,a[j].p,j,i+1);
          end;
    end;
  used[k]:=false;
end;

var
  i,j:word;

begin
  assign(input,'jeu.dat');
  reset(input);
  assign(output,'jeu.res');
  rewrite(output);
  read(n);
  for i:=1 to n do
    read(a[i].p,a[i].k);
  fillchar(u,sizeof(u),0);
  for i:=1 to n do
    if not u[i] then
      begin
        u[i]:=true;
        srch(a[i].p,a[i].k,i,1);
        if a[i].p<>a[i].k then srch(a[i].k,a[i].p,i,1);
      end;
  close(input);
  close(output);
end.
 
