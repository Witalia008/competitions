program lakes;
{$APPTYPE CONSOLE}
const
  nmax=100;
  kk:array[1..4,1..2]of smallint=((1,0),(-1,0),(0,1),(0,-1));
var
  a,po:array[0..nmax+1,0..nmax+1]of smallint;
  ans:array[0..nmax*nmax]of longword;
  queue:array[1..2,1..nmax*nmax*3]of longword;
  n,m,i,j,head,tail,o,p,k,ks,max,l:longword;
begin
  assign(input,'input.txt');
  reset(input);
  assign(output,'output.txt');
  rewrite(output);
  read(n,m,k);
  fillchar(a,sizeof(a),-1);
  for i:=1 to k do
    begin
      read(o,p);
      a[o,p]:=0;
    end;
  ks:=0;
  for i:=1 to n do
    for j:=1 to m do
      if (a[i,j]=0)and(po[i,j]=0) then
        begin
          inc(ks);
          queue[1,1]:=i;
          queue[2,1]:=j;
          head:=1;
          tail:=2;
          po[i,j]:=ks;
          while head<tail do
            begin
              o:=queue[1,head];
              p:=queue[2,head];
              inc(head);
              for l:=1 to 4 do
                if (a[o+kk[l,1],p+kk[l,2]]=0)and(po[o+kk[l,1],p+kk[l,2]]=0) then
                  begin
                    po[o+kk[l,1],p+kk[l,2]]:=ks;
                    queue[1,tail]:=o+kk[l,1];
                    queue[2,tail]:=p+kk[l,2];
                    inc(tail);
                  end;
            end;
        end;
  max:=0;
  for i:=1 to n do
    for j:=1 to m do
      inc(ans[po[i,j]]);
  for i:=1 to n*m do
    if ans[i]>max then
      max:=ans[i];
  writeln(max);    
  close(input);
  close(output);
end.
 