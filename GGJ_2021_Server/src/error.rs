pub type Result<T> = std::result::Result<T, Error>;

#[derive(Debug)]
pub enum Error {
  IOError(tokio::io::Error),
  NetError(String),
  ChannelError(String),
  MiscError(String),
}

impl std::error::Error for Error {}

impl std::fmt::Display for Error {
  fn fmt(&self, f : &mut ::core::fmt::Formatter) -> ::core::fmt::Result {
    match self {
      Error::IOError(e) => write!(f, "IO Error: {}", e),
      Error::NetError(e) => write!(f, "Net Error: {}", e),
      Error::ChannelError(e) => write!(f, "Channel Error: {}", e),
      Error::MiscError(e) => write!(f, "(Error) {}", e)
    }
  }
}

impl From<std::io::Error> for Error {
  fn from(e : std::io::Error) -> Self {
    Self::IOError(e)
  }
}

impl<T> From<async_channel::SendError<T>> for Error {
  fn from(e : async_channel::SendError<T>) -> Self {
    Self::ChannelError(format!("{}", e))
  }
}

impl From<tokio::task::JoinError> for Error {
  fn from(e : tokio::task::JoinError) -> Self {
    Self::MiscError(format!("Tokio error: {}", e))
  }
}