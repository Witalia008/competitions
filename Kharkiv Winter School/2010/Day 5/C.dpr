program EasyMaxSum;
 {$APPTYPE CONSOLE}
 var
  i,j:longword;
  max,n,m,a1,a2:int64;
  a,g,f:array[1..500,1..500]of int64;
 begin
  assign(input,'input.txt');
  reset(input);
  assign(output,'output.txt');
  rewrite(output);
  read(n,m);
  fillchar(a,sizeof(a),0);
  fillchar(g,sizeof(g),0);
  fillchar(f,sizeof(f),0);
  for i:=1 to n do
    for j:=1 to m do
      read(a[i,j]);
  for i:=1 to m do
    f[1,i]:=a[1,i];
  for j:=1 to m do
    g[1,j]:=1;
  for i:=2 to n do
    for j:=1 to m do
      begin
        max:=f[i-1,j];
        if (j>1)and(f[i-1][j-1]>max)then max:=f[i-1][j-1];
        if (j<m)and(f[i-1][j+1]>max)then max:=f[i-1][j+1];
        f[i][j]:=max+a[i][j];
        g[i][j]:=0;
        if (j>1)and(f[i-1][j-1]=max)then g[i][j]:=g[i][j]+g[i-1][j-1];
        if (f[i-1][j]=max)then g[i][j]:=g[i][j]+g[i-1][j];
        if (j<m)and(f[i-1][j+1]=max)then g[i][j]:=g[i][j]+g[i-1][j+1];
      end;
  a1:=f[n][1];
  a2:=0;
  for i:=1 to m do
    if f[n][i]>a1 then
      a1:=f[n][i];
  for i:=1 to m do
    if f[n][i]=a1 then a2:=a2+g[n][i];    
  writeln(a1,' ',a2);
  close(input);
  close(output);
 end.
