package api

type GeneralError struct {
	message string
}

func (e *GeneralError) Error() string {
	return e.message
}
