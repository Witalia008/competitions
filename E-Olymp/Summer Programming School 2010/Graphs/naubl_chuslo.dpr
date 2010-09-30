program naubl_chuslo;
{$APPTYPE CONSOLE}
const
  nmax=200;
  k:array[1..4,1..2]of smallint=((1,0),(-1,0),(0,1),(0,-1));
type
  tmas=array[0..nmax+1,0..nmax+1]of longint;
var
  a,p,d,ans:tmas;
  queue:array[1..2,1..nmax*nmax]of longint;
  n,i,j,l,o,u,head,tail:longword;
  fl:boolean;
begin
  assign(input,'input.txt');
  reset(input);
  assign(output,'output.txt');
  rewrite(output);
  read(n);
  fillchar(a,sizeof(a),-1);
  fillchar(d,sizeof(d),0);
  fillchar(ans,sizeof(ans),0);
  for i:=1 to n do
    for j:=1 to n do
      read(a[i][j]);
  for o:=1 to n do
    for u:=1 to n do
      begin
        if a[o][u]<>0 then ans[o][u]:=a[o][u] else
          begin
            fl:=false;
            head:=1;
            tail:=2;
            queue[1][1]:=o;
            queue[2][1]:=u;
            fillchar(p,sizeof(p),0);
            p[o][u]:=1;
            while (head<tail)and(not fl) do
              begin
                i:=queue[1,head];
                j:=queue[2,head];
                if a[i][j]<>0 then
                  begin
                    if (d[o][u]=0) then
                      begin
                        fl:=false;
                        d[o][u]:=abs(i-o)+abs(j-u);
                        ans[o][u]:=a[i][j];
                      end else
                      if abs(i-o)+abs(j-u)=d[o][u] then
                        begin
                          fl:=true;
                          break;
                        end else break;
                  end;
                inc(head);
                if (a[i][j]=0)and(d[o][u]=0) then
                  for l:=1 to 4 do
                    if (p[i+k[l][1]][j+k[l][2]]=0)and(a[i+k[l][1]][j+k[l][2]]<>-1) then
                      begin
                        p[i+k[l][1]][j+k[l][2]]:=1;
                        queue[1][tail]:=i+k[l][1];
                        queue[2][tail]:=j+k[l][2];
                        inc(tail);
                      end;
              end;
            if fl then ans[o][u]:=0;
          end;
      end;
  for i:=1 to n do
    begin
      write(ans[i][1]);
      for j:=2 to n do
        write(' ',ans[i][j]);
      writeln;
    end;
  close(input);
  close(output);
end.
