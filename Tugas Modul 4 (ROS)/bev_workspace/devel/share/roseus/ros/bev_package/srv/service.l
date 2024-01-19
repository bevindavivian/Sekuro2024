;; Auto-generated. Do not edit!


(when (boundp 'bev_package::service)
  (if (not (find-package "BEV_PACKAGE"))
    (make-package "BEV_PACKAGE"))
  (shadow 'service (find-package "BEV_PACKAGE")))
(unless (find-package "BEV_PACKAGE::SERVICE")
  (make-package "BEV_PACKAGE::SERVICE"))
(unless (find-package "BEV_PACKAGE::SERVICEREQUEST")
  (make-package "BEV_PACKAGE::SERVICEREQUEST"))
(unless (find-package "BEV_PACKAGE::SERVICERESPONSE")
  (make-package "BEV_PACKAGE::SERVICERESPONSE"))

(in-package "ROS")





(defclass bev_package::serviceRequest
  :super ros::object
  :slots (_komponenX _komponenY _komponenZ ))

(defmethod bev_package::serviceRequest
  (:init
   (&key
    ((:komponenX __komponenX) 0.0)
    ((:komponenY __komponenY) 0.0)
    ((:komponenZ __komponenZ) 0.0)
    )
   (send-super :init)
   (setq _komponenX (float __komponenX))
   (setq _komponenY (float __komponenY))
   (setq _komponenZ (float __komponenZ))
   self)
  (:komponenX
   (&optional __komponenX)
   (if __komponenX (setq _komponenX __komponenX)) _komponenX)
  (:komponenY
   (&optional __komponenY)
   (if __komponenY (setq _komponenY __komponenY)) _komponenY)
  (:komponenZ
   (&optional __komponenZ)
   (if __komponenZ (setq _komponenZ __komponenZ)) _komponenZ)
  (:serialization-length
   ()
   (+
    ;; float64 _komponenX
    8
    ;; float64 _komponenY
    8
    ;; float64 _komponenZ
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _komponenX
       (sys::poke _komponenX (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _komponenY
       (sys::poke _komponenY (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _komponenZ
       (sys::poke _komponenZ (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _komponenX
     (setq _komponenX (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _komponenY
     (setq _komponenY (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _komponenZ
     (setq _komponenZ (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(defclass bev_package::serviceResponse
  :super ros::object
  :slots (_magnitude ))

(defmethod bev_package::serviceResponse
  (:init
   (&key
    ((:magnitude __magnitude) 0.0)
    )
   (send-super :init)
   (setq _magnitude (float __magnitude))
   self)
  (:magnitude
   (&optional __magnitude)
   (if __magnitude (setq _magnitude __magnitude)) _magnitude)
  (:serialization-length
   ()
   (+
    ;; float64 _magnitude
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _magnitude
       (sys::poke _magnitude (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _magnitude
     (setq _magnitude (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(defclass bev_package::service
  :super ros::object
  :slots ())

(setf (get bev_package::service :md5sum-) "55d1a215f43fd1f64eb105a505b172c4")
(setf (get bev_package::service :datatype-) "bev_package/service")
(setf (get bev_package::service :request) bev_package::serviceRequest)
(setf (get bev_package::service :response) bev_package::serviceResponse)

(defmethod bev_package::serviceRequest
  (:response () (instance bev_package::serviceResponse :init)))

(setf (get bev_package::serviceRequest :md5sum-) "55d1a215f43fd1f64eb105a505b172c4")
(setf (get bev_package::serviceRequest :datatype-) "bev_package/serviceRequest")
(setf (get bev_package::serviceRequest :definition-)
      "float64 komponenX
float64 komponenY
float64 komponenZ
---
float64 magnitude
")

(setf (get bev_package::serviceResponse :md5sum-) "55d1a215f43fd1f64eb105a505b172c4")
(setf (get bev_package::serviceResponse :datatype-) "bev_package/serviceResponse")
(setf (get bev_package::serviceResponse :definition-)
      "float64 komponenX
float64 komponenY
float64 komponenZ
---
float64 magnitude
")



(provide :bev_package/service "55d1a215f43fd1f64eb105a505b172c4")


