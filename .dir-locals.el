;;; Directory Local Variables
;;; For more information see (info "(emacs) Directory Variables")

(
 (nil
  . ((dir-local-docker-config-alists
      . (
         ((docker-image-id . "cpp_engine")
          (docker-container-name . "cpp-lsp-docker")
          (lsp-docker-client-configs
           . ((:server-id ccls :docker-server-id ccls-docker :server-command "ccls"))))
         ((docker-image-id . "ml_gpu_jupyter")
          (docker-container-name . "py-lsp-docker")
          (lsp-docker-client-configs
           . ((:server-id pyls :docker-server-id pyls-docker :server-command "pyls"))))
         ))
     ))
 )
