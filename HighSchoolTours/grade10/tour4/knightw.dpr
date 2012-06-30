program knightw;
{$APPTYPE CONSOLE}
const
  nmax=1000;
type
  tmas=array[-1..nmax+2,-1..nmax+2]of longint;
const
  kk:array[1..8,1..2]of shortint=((2,1),(2,-1),(1,2),(1,-2),(-2,1),(-2,-1),(-1,2),(-1,-2));
var
  n,i,j,head,tail,iis,iif,jjs,jjf,k:longint;
  queue:array[1..2,1..100000]of longint;
  a,ans:tmas;
  q:char;
  fl:boolean;
begin
  Assign(Input,'knightw.in');
  Reset(Input);
  Assign(Output,'knightw.out');
  Rewrite(Output);
  readln(n);
  fl:=false;
  fillchar(a,sizeof(a),-1);
  fillchar(queue,sizeof(queue),0);
  for i := 1 to n do
    begin
      for j := 1 to n do
        begin
          read(q);
          if q='.' then a[i][j]:=0;
          if q='@' then
            begin
              if not fl then
                begin
                  iis:=i;
                  jjs:=j;
                  a[i][j]:=0;
                  fl:=true;
                end else
                begin
                  iif:=i;
                  jjf:=j;
                  a[i][j]:=0;
                end;           
            end;
        end;
      readln;
    end;
  ans:=a;
  head:=1;
  tail:=2;
  queue[1][1]:=iis;
  queue[2][1]:=jjs;
  a[iis][jjs]:=1;
  while head<tail do
    begin
      i:=queue[1][head];
      j:=queue[2][head];
      inc(head);
      for k := 1 to 8 do
        if (a[i+kk[k][1]][j+kk[k][2]]=0)and((a[i+kk[k][1]][j+kk[k][2]]>a[i][j]+1)or(a[i+kk[k][1]][j+kk[k][2]]=0)) then
          begin
            queue[1][tail]:=i+kk[k][1];
            queue[2][tail]:=j+kk[k][2];
            inc(tail);
            a[i+kk[k][1]][j+kk[k][2]]:=a[i][j]+1;
          end;
    end;
  ans[iis][jjs]:=2;
  ans[iif][jjf]:=2;
  if a[iif][jjf]=0 then writeln('Impossible')else
    begin
      i:=iif;
      j:=jjf;
      while (i<>iis)or(j<>jjs) do
        begin
          for k := 1 to 8 do
            if (a[i+kk[k][1]][j+kk[k][2]]=a[i][j]-1) then
              begin
                i:=i+kk[k][1];
                j:=j+kk[k][2];
                ans[i][j]:=2;
                break;
              end;
        end;
        for i := 1 to n do
          begin
            for j := 1 to n do
              begin
                if ans[i][j]=0 then write('.');
                if ans[i][j]=-1 then write('#');
                if ans[i][j]=2 then write('@');
              end;
            writeln;
          end;
    end;
  Close(Input);
  Close(Output);
end.
