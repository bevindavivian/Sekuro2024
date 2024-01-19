
(cl:in-package :asdf)

(defsystem "bev_package-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "service" :depends-on ("_package_service"))
    (:file "_package_service" :depends-on ("_package"))
  ))