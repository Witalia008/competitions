program fibostr;
{$apptype console}
const
   maxn=45;
function ent(a,b:string):integer;
var
  i,j,count:integer;
  fl:boolean;
begin
  count:=0;
  for i:=1 to length(a)-length(b)+1 do
    begin
      fl:=true;
      for j:=1 to length(b) do
        if a[i+j-1]<>b[j] then
           fl:=false;
      if fl then inc(count);
    end;
  ent:=count;
end;

var
  f:array[1..12]of string;
  fb,fe:array[1..maxn]of string;
  fc:array[1..maxn]of longint;
  n,i,ss:integer;
  s:string;
begin
  assign(input,'fibostr.in');
  reset(input);
  assign(output,'fibostr.out');
  rewrite(output);
  readln(n);
  readln(s);
  f[1]:='A';
  f[2]:='B';
  for i:=3 to 12 do
    f[i]:=f[i-1]+f[i-2];
  if n<=12 then writeln(ent(f[n],s))else
    begin
      ss:=length(s);
      fb[11]:=copy(f[11],1,ss-1);
      fe[11]:=copy(f[11],length(f[11])-ss+2,ss-1);
      fc[11]:=ent(f[11],s);
      fb[12]:=copy(f[12],1,ss-1);
      fe[12]:=copy(f[12],length(f[12])-ss+2,ss-1);
      fc[12]:=ent(f[12],s);
      for i := 13 to n do
        begin
          fb[i]:=fb[i-1];
          fe[i]:=fe[i-2];
          fc[i]:=fc[i-1]+fc[i-2]+ent(fe[i-1]+fb[i-2],s);
        end;
      writeln(Fc[n]);
    end;
  close(input);
  close(output);
end.
