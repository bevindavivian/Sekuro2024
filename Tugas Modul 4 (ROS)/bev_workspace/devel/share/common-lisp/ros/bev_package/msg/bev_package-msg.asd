
(cl:in-package :asdf)

(defsystem "bev_package-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "Pesan" :depends-on ("_package_Pesan"))
    (:file "_package_Pesan" :depends-on ("_package"))
  ))