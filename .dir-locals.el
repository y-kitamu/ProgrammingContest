;;; Directory Local Variables
;;; For more information see (info "(emacs) Directory Variables")

(
 (nil
  . ((docker-image-id . "cpp_engine")
     (docker-container-name . "cpp-engine-lsp-container")
     (lsp-docker-client-configs
      . ((:server-id ccls :docker-server-id ccls-cpp-engine-docker :server-command "ccls")))
     ))
 )
