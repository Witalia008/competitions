program drobova_aryfmetuka;
{$APPTYPE CONSOLE}
{$O-}

procedure ins(var a,b,c:longint;s:string);
var
  i,j,cod:longint;
begin
  b:=0;
  a:=0;
  c:=0;
  if pos('/',s)<>0 then
    begin
      if pos(' ',s)<>0 then
        begin
          if ord(s[1])>=48 then i:=1 else i:=2;
          while s[i]<>' ' do
            begin
              a:=a*10+ord(s[i])-48;
              inc(i);
            end;
          if s[1]='-' then a:=-a; 
          delete(s,1,pos(' ',s));
        end;
      if ord(s[1])>=48 then i:=1 else i:=2;
      while s[i]<>'/' do
        begin
          b:=b*10+ord(s[i])-48;
          inc(i);
        end;
      if s[1]='-' then b:=-b;
      delete(s,1,pos('/',s));
      if ord(s[1])>=48 then i:=1 else i:=2;
      while i<=length(s) do
        begin
          c:=c*10+ord(s[i])-48;
          inc(i);
        end;
      if s[1]='-' then c:=-c;  
    end else val(s,a,cod);
end;

function gcd(a,b:longword):longword;
begin
  while (a<>0)and(b<>0)do
    if a>b then a:=a mod b else b:=b mod a;
  if a=0 then gcd:=b else gcd:=a;
end;

var
  a,b,p1,q1,p2,q2,lsk,ans,aa,bb,c:longint;
  s:string;
  q:char;
begin
  assign(input,'input.txt');
  reset(input);
  assign(output,'output.txt');
  rewrite(output);
  readln(s);
  ins(a,p1,q1,s);
  //if p1=0 then p1:=1;
  if q1=0 then q1:=1;
  p1:=p1+abs(a)*q1;
  readln(q);
  readln(s);
  ins(b,p2,q2,s);
  //if p2=0 then p2:=1;
  if q2=0 then q2:=1;
  p2:=p2+abs(b)*q2;
  if q='+' then
    begin
      if gcd(abs(q1),abs(q2))<>0 then lsk:=(abs(q1*q2))div gcd(abs(q1),abs(q2)) else lsk:=0;
      if q1<>0 then p1:=p1*(lsk div q1) else p1:=0;
      if q2<>0 then p2:=p2*(lsk div q2) else p2:=0;
      q1:=lsk;
      q2:=lsk;
      if a<0 then p1:=-p1;
      if b<0 then p2:=-p2;
      ans:=p1+p2;
      if (lsk<>0)and(ans mod lsk=0) then writeln(ans div lsk)else
        begin
          if lsk<>0 then a:=ans div lsk else a:=0;
          if (lsk<>0)and(gcd(abs(ans),abs(lsk))<>0) then b:=(ans mod lsk) div gcd(abs(ans),abs(lsk)) else b:=0;
          if gcd(abs(lsk),abs(ans))<>0 then c:=lsk div gcd(abs(lsk),abs(ans)) else c:=0;
          if a<>0 then
            begin
              write(a,' ');
              b:=abs(b);
              c:=abs(c);
            end;
          writeln(b,'/',c);
        end;
    end;
  if q='-' then
    begin
      if gcd(abs(q1),abs(q2))<>0 then lsk:=(abs(q1*q2))div gcd(abs(q1),abs(q2)) else lsk:=0;
      if q1<>0 then p1:=p1*(lsk div q1) else p1:=0;
      if q2<>0 then p2:=p2*(lsk div q2) else p2:=0;
      q1:=lsk;
      q2:=lsk;
      if a<0 then p1:=-p1;
      if b<0 then p2:=-p2;
      ans:=p1-p2;
      if (lsk<>0)and(ans mod lsk=0) then writeln(ans div lsk)else
        begin
          if lsk<>0 then a:=ans div lsk else a:=0;
          if (lsk<>0)and(gcd(abs(ans),abs(lsk))<>0)  then b:=(ans mod lsk) div gcd(abs(ans),abs(lsk)) else b:=0;
          if gcd(abs(lsk),abs(ans))<>0 then c:=lsk div gcd(abs(lsk),abs(ans)) else c:=0;
          if a<>0 then
            begin
              write(a,' ');
              b:=abs(b);
              c:=abs(c);
            end;
          writeln(b,'/',c);
        end;
    end;
  if q='*' then
    begin
      if a<0 then p1:=-p1;
      if b<0 then p2:=-p2;
      aa:=p1*p2;
      bb:=q1*q2;
      if (bb<>0)and(aa mod bb=0) then writeln(aa div bb)else
        begin
          if bb<>0 then a:=aa div bb else a:=0;
          if (bb<>0)and(gcd(abs(aa),abs(bb))<>0) then b:=(aa mod bb)div gcd(abs(aa),abs(bb)) else b:=0;
          if gcd(abs(aa),abs(bb))<>0 then c:=bb div gcd(abs(aa),abs(bb)) else c:=0;;
          if a<>0 then
            begin
              write(a,' ');
              b:=abs(b);
              c:=abs(c);
            end;
          writeln(b,'/',c);
        end;
    end;
  if q='/' then
    begin
      if a<0 then p1:=-p1;
      if b<0 then p2:=-p2;
      aa:=p1*q2;
      bb:=q1*p2;
      if (bb<>0)and(aa mod bb=0) then writeln(aa div bb)else
        begin
          if bb<>0 then a:=aa div bb else a:=0;
          if (bb<>0)and(gcd(abs(aa),abs(bb))<>0) then b:=(aa mod bb)div gcd(abs(aa),abs(bb)) else b:=0;
          if gcd(abs(aa),abs(bb))<>0 then c:=bb div gcd(abs(aa),abs(bb)) else c:=0;
          if a<>0 then
            begin
              write(a,' ');
              b:=abs(b);
              c:=abs(c);
            end;
          writeln(b,'/',c);
        end;
    end;
  close(input);
  close(output);
end.
