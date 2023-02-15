# GMaddon

### To Use
- Run executable as `gmaddon.exe [dir]`. The optional `dir` field specifies the 
output directory of the newly-created addon; if left empty, the output directory
will default to the directory of the executable.
- Fill out the following prompts with addon name, version, author, etc.
- Your "framework" is done! You may now create Lua files under `<addon name>/lua/<addon name>`
with the prefixes `cl_`, `sv_`, and `sh_` and they will be automatically sent, loaded, 
and executed on the client, server, or both, respectively.


### Template/Framework Structure

```
<addon name>
 ↳ lua
    ↳ autorun
       ↳ <addon name>.lua    <- Entry-point loader file.
       ↳ bk_loader.lua       <- Autoloader support file.
    ↳ <addon name>
       ↳ ...                 <- Place files here.
       ↳ cl_example.lua      <- Automatically AddCSLuaFile'd and included on client.
       ↳ sv_example.lua      <- Automatically included on server.
       ↳ sh_example.lua      <- Does both of the previous actions for client and server.
       
```