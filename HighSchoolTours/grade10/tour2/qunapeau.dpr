program qunapeau;
{$APPTYPE CONSOLE}
var
  s,c,ans:string;
  n,co,m:longword;
  sum,b:int64;
  zn:shortint;
  fl:boolean;
  a:array[0..20]of byte;
begin
  assign(input,'qunapeau.dat');
  reset(input);
  assign(output,'qunapeau.res');
  rewrite(output);
  read(s);
  c:=copy(s,pos('=',s)+1,length(s)-pos('=',s));
  delete(s,pos('=',s),length(s)-pos('=',s)+1);
  val(c,m,co);
  fillchar(a,sizeof(a),0);
  fl:=true;
  n:=length(s);
  while fl do
    begin
      b:=0;
      sum:=0;
      if a[1]=2 then zn:=-1 else zn:=1;
      for co := 1 to n do
        begin
          if a[co]=0 then b:=b*10+ord(s[co])-ord('0');
          if a[co]=1 then
            begin
              sum:=sum+zn*b;
              b:=ord(s[co])-ord('0');
              zn:=1;
            end;
          if a[co]=2 then
            begin
              sum:=sum+zn*b;
              b:=ord(s[co])-ord('0');
              zn:=-1;
            end;
        end;
      sum:=sum+zn*b;
      if (sum=m)and(a[1]<>1) then
        begin
          ans:='';
          for co := 1 to n do
            begin
              if a[co]=1 then ans:=ans+'+';
              if a[co]=2 then ans:=ans+'-';
              ans:=ans+s[co];
            end;
          co:=1;
          ans:=ans+'=';
          while co<=length(ans) do
            begin
              b:=0;
              while not (ans[co] in ['-','+','=']) do
                begin
                  b:=b*10+ord(ans[co])-ord('0');
                  inc(co);
                end;
              if co<>1 then write(b);
              write(ans[co]);
              inc(co);
            end;
          writeln(c);
        end;
      co:=n;
      while a[co]=2 do
        begin
          a[co]:=0;
          dec(co);
        end;
      if co=0 then fl:=false else inc(a[co]);
    end;
  close(input);
  close(output);
end.
