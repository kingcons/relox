(lang dune 1.11)
(name relox)
(version 0.1.0)
(source (github kingcons/relox))
(license MIT)
(authors "Brit Butler")
(maintainers "Brit Butler")

(using fmt 1.2 (enabled_for reason))

(package
 (name relox)
 (synopsis "A lox interpreter in ReasonML")
 (depends
  reason
  dune
  rely
  base
  cmdliner
  lwt
  console
  pastel))
