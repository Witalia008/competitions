program java_vs_cpp;
{$APPTYPE CONSOLE}
const
  big:set of char=['A'..'Z'];
  lit:set of char=['a'..'z'];
var
  s,ans:string;
  i,j,l:longword;
  fl:boolean;
begin
  assign(input,'input.txt');
  reset(input);
  assign(output,'output.txt');
  rewrite(output);
  readln(s);
  if pos('_',s)<>0 then
    begin
      fl:=true;
      if s[1]='_' then fl:=false;
      if s[length(s)]='_' then fl:=false;
      for i:=1 to length(s) do
        if not (s[i] in lit)and(s[i]<>'_') then fl:=false;
      for i:=1 to length(s) do
        if (s[i]='_')and(s[i+1]='_')then fl:=false;
      if not fl then writeln('Error!')else
        begin
          for i:=1 to length(s) do
            if s[i]='_' then
              begin
                delete(s,i,1);
                s[i]:=chr(ord(s[i])-32);
              end;
          writeln(s);
        end;
    end else
    begin
      fl:=true;
      if not (s[1] in lit) then fl:=false;
      for i:=2 to length(s) do
        if not (s[i] in big) and not (s[i] in lit) then fl:=false;
      if not fl then writeln('Error!')else
        begin
          ans:='';
          for i:=1 to length(s) do
            if s[i] in big then
              ans:=ans+'_'+chr(ord(s[i])+32)
                else ans:=ans+s[i];
          writeln(ans);
        end;
    end;
  close(input);
  close(output);
end.
