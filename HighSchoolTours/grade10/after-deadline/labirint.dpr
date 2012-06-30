program labirint;
{$APPTYPE CONSOLE}
const
  nmax=3334;
  kk:array[1..4,1..2]of shortint=((1,0),(-1,0),(0,1),(0,-1));
type
  tmas=array[0..nmax+1,0..nmax+1]of longint;
var
  a:tmas;
  q:char;
  ans:string;
  n,m,iss,jss,i,j,head,tail,k,min,iif,jjf:longint;
  queue:array[1..2,1..100000]of longint;
begin
  Assign(Input,'labirint.dat');
  Reset(Input);
  Assign(Output,'labirint.res');
  Rewrite(Output);
  readln(n,m);
  fillchar(a,sizeof(a),0);
  fillchar(queue,sizeof(queue),0);
  if (n<=2)or(m<=2) then writeln(0) else begin

  for i := 1 to n do
    begin
      a[i][0]:=-1;
      a[i][m+1]:=-1;
    end;
  for j := 1 to m do
    begin
      a[0][j]:=-1;
      a[n+1][j]:=-1;
    end;
  for i := 1 to n do
    begin
      for j := 1 to m do
        begin
          read(q);
          if q='#' then a[i][j]:=-1;
          if q='+' then
            begin
              iss:=i;
              jss:=j;
            end;
        end;
      readln;
    end;
  a[iss][jss]:=1;
  head:=1;
  tail:=2;
  queue[1][1]:=iss;
  queue[2][1]:=jss;
  while head<tail do
    begin
      i:=queue[1][head];
      j:=queue[2][head];
      inc(head);
      for k := 1 to 4 do
        if (a[i+kk[k][1]][j+kk[k][2]]=0)or(a[i+kk[k][1]][j+kk[k][2]]>a[i][j]+1) then
          begin
            queue[1][tail]:=i+kk[k][1];
            queue[2][tail]:=j+kk[k][2];
            inc(tail);
            a[i+kk[k][1]][j+kk[k][2]]:=a[i][j]+1;
          end;
    end;
  ans:='';
  min:=n*m*nmax;
  for i := 1 to n do
    begin
      if (a[i][1]<min)and(a[i][1]>0) then
        begin
          min:=a[i][1];
          iif:=i;
          jjf:=1;
        end;
      if (a[i][m]<min)and(a[i][m]>0) then
        begin
          min:=a[i][m];
          iif:=i;
          jjf:=m;
        end;
    end;
  for j := 1 to m do
    begin
      if (a[1][j]<min)and(a[1][j]>0) then
        begin
          min:=a[1][j];
          iif:=1;
          jjf:=j;
        end;
      if (a[n][j]<min)and(a[n][j]>0) then
        begin
          min:=a[n][j];
          iif:=n;
          jjf:=j;
        end;
    end;
  i:=iif;
  j:=jjf;
  if min=m*n*nmax then writeln(-1)else
  begin
    writeln(a[iif][jjf]-1);
  if a[iif][jjf]-1<>0 then
    begin
      while (j<>jss)or(i<>iss) do
        begin
          if a[i-1][j]=a[i][j]-1 then
            begin
              dec(i);
              ans:='s'+ans;
            end else
          if a[i+1][j]=a[i][j]-1 then
            begin
              inc(i);
              ans:='n'+ans;
            end else
          if a[i][j-1]=a[i][j]-1 then
            begin
              dec(j);
              ans:='e'+ans;
            end else
          if a[i][j+1]=a[i][j]-1 then
            begin
              inc(j);
              ans:='w'+ans;
            end;
        end;
      writeln(ans);
    end;
  end;
  end;
  Close(Input);
  Close(Output);
end.
