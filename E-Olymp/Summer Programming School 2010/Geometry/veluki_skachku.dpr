program veluki_skachku;
{$APPTYPE CONSOLE}
type
  tmas=array[1..200000]of record
                           x,y:real;
                           p:char;
                         end;
procedure swapr(var a,b:real);
var
  t:real;
begin
  t:=a;
  a:=b;
  b:=t;
end;

procedure swapc(var a,b:char);
var
  t:char;
begin
  t:=a;
  a:=b;
  b:=t;
end;

procedure sort(var a:tmas;l,r:longword);
var
  et:real;
  i,j:longword;
begin
  if (l=r-1)and(a[l].x<a[r].x)then exit;
  i:=l;
  j:=r;
  et:=a[(l+r)div 2].x;
  while i<j do
    begin
      while a[i].x<et do inc(i);
      while a[j].x>et do dec(j);
      if i<j then
        begin
          swapr(a[i].x,a[j].x);
          swapr(a[i].y,a[j].y);
          swapc(a[i].p,a[j].p);
          inc(i);
          dec(j);
        end;
    end;
  if i<r then sort(a,i,r);
  if j>l then sort(a,l,j);  
end;

var
  mas:tmas;
  n,i,j,top,k,l:longword;
  x1,x2,y1,y2,a,b,c,x,y,t:int64;
  ans,x0,y0,d,mult,ax,ay,bx,by,z,q,r,v:extended;
  fl:boolean;
begin
  assign(input,'input.txt');
  reset(input);
  assign(output,'output.txt');
  rewrite(output);
  read(x1,y1,x2,y2);
  read(n);
  top:=0;
  ans:=0;
  for i:=1 to n do
    begin
      read(x,y,r);
      a:=y1-y2;
      b:=x2-x1;
      if b=0 then
        begin
          b:=a;
          a:=0;
          t:=x;
          x:=y;
          y:=t;
        end;
      v:=a*a+b*b;
      c:=x1*y2-x2*y1;
      c:=c+a*x+b*y;
      x0:=-a*c/v;
      y0:=-b*c/v;
      if abs(c)<abs(r)*sqrt(v) then
        begin
	        d:=r*r-c*c/v;
	        mult:=sqrt(d/v);
	        ax:=x0+b*mult;
	        bx:=x0-b*mult;
	        ay:=y0-a*mult;
	        by:=y0+a*mult;
          inc(top);
          mas[top].x:=ax+x;
          mas[top].y:=ay+y;
          if ax<bx then mas[top].p:='p' else mas[top].p:='k';
          inc(top);
          mas[top].x:=bx+x;
          mas[top].y:=by+y;
          if ax<bx then mas[top].p:='k' else mas[top].p:='p';
        end;
    end;
  sort(mas,1,top);
  k:=0;
  l:=0;
  for i:=1 to top do
    begin
      if mas[i].p='p' then
        begin
          k:=k+1;
          fl:=true;
        end else
        begin
          l:=l+1;
          fl:=false;
        end;
      if k=l then
        ans:=ans+sqrt(sqr(mas[i].x-x0)+sqr(mas[i].y-y0));
      if (l+1=k)and fl then
        begin
          x0:=mas[i].x;
          y0:=mas[i].y;
        end;
    end;
  writeln(ans:0:4);  
  close(input);
  close(output);
end.
