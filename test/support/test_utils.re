open Relox;

/** Create a new temporary directory.

    The directory name will be prefixed with "relox-test-" and will be suffixed with a timestamp. */
let get_tempdir = name => {
  Printf.sprintf(
    "relox-test-%s-%s",
    name,
    Unix.time() |> Float.to_int |> Int.to_string,
  )
  |> Caml.Filename.concat(Caml.Filename.get_temp_dir_name());
};

/** Run relox binary with the given arguments and return the standard output. */
let run = args => {
  let arguments = args |> Array.append([|"esy", "start"|]);

  let env =
    Unix.environment()
    |> Array.append([|
         Printf.sprintf(
           "%s=%s",
           Relox.Config.RELOX_CACHE_DIR.name,
           get_tempdir("cache_dir"),
         ),
       |]);

  Lwt_process.pread_chars(~env, ("", arguments))
  |> Lwt_stream.to_string
  |> Lwt_main.run;
};
